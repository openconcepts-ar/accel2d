// This file is Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <atomic>
#include <cstddef>
#include <cstring>
#include <type_traits>

#include <atomic>
#include <cstddef>
#include <cstring>
#include <cassert>
#include <type_traits>

template<typename T>
class AtomicFifo
{
private:
    T* _buffer;
    size_t _size;
    std::atomic<size_t> _head;
    std::atomic<size_t> _tail;

public:
    AtomicFifo(T* buffer, size_t size)
        : _buffer(buffer),
          _size(size),
          _head(0),
          _tail(0)
    {
        assert(buffer != nullptr);
        assert(size > 1);
    }

    AtomicFifo(const AtomicFifo&) = delete;
    AtomicFifo& operator=(const AtomicFifo&) = delete;

    bool push(const T& item)
    {
        size_t head = _head.load(std::memory_order_relaxed);
        size_t next = (head + 1) % _size;
        if (next == _tail.load(std::memory_order_acquire))
            return false; // full

        _buffer[head] = item;
        _head.store(next, std::memory_order_release);
        return true;
    }

    bool pop(T& out)
    {
        size_t tail = _tail.load(std::memory_order_relaxed);
        if (tail == _head.load(std::memory_order_acquire))
            return false; // empty

        out = _buffer[tail];
        _tail.store((tail + 1) % _size, std::memory_order_release);
        return true;
    }

    size_t size() const
    {
        size_t head = _head.load(std::memory_order_acquire);
        size_t tail = _tail.load(std::memory_order_acquire);
        return (head + _size - tail) % _size;
    }

    size_t capacity() const { return _size - 1; }
    bool empty() const { return _head.load() == _tail.load(); }
    bool full() const { return ((_head.load() + 1) % _size) == _tail.load(); }
};

struct hal_fifo : AtomicFifo<USBMessage>
{
	using AtomicFifo<USBMessage>::AtomicFifo;
};

hal_queue_handle_t hal_queue_create(size_t n, size_t sz, void *buffer)
{
	assert(sz == sizeof(USBMessage));
	return new hal_fifo((USBMessage *) buffer, n/sizeof(USBMessage));
}

void hal_queue_send(hal_queue_handle_t fifo, USBMessage *msg)
{
	fifo->push(*msg);	
}

bool hal_queue_receive(hal_queue_handle_t fifo, USBMessage *msg)
{
	return fifo->pop(*msg);
}

hal_queue_handle_t usb_msg_queue;

