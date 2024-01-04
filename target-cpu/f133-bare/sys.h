// (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef __SYS_H__
#define __SYS_H__

#define F_XTAL 24000000

static inline uint64_t cpu_count(void)
{
	uint64_t value;
	 __asm__ __volatile__("csrr %0, time\n" : "=r"(value) :: "memory");
	return value;
}

static inline void delay_us(unsigned long us)
{
	uint64_t t1 = cpu_count() + us * F_XTAL/1000000;
	int64_t dt;
	do {
		dt = t1 - cpu_count();
	} while(dt > 0);
}

#endif
