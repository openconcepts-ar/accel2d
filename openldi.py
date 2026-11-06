from migen import *

from litex.gen import LiteXModule
from litex.soc.interconnect import stream
from litex.soc.cores.video import video_data_layout

class VideoOPENLDIPHY(LiteXModule):
    def __init__(self, pads, clock_domain="sys", clock_domain3p5x="sys3p5x", pn_swap=[]):
        self.sink = sink = stream.Endpoint(video_data_layout)

        # # #

        # Always ack Sink, no backpressure.
        self.comb += sink.ready.eq(1)
        r, g, b, de, hs, vs = sink.r, sink.g, sink.b, sink.de, sink.hsync, sink.vsync

        def xdr7(out_q, in_d, invert=False):
           d = in_d if not invert else ~in_d
           self.specials += Instance("ODDR71B",
               i_SCLK=ClockSignal(clock_domain),
               i_ECLK=ClockSignal(clock_domain3p5x), #3.5x speed of SCLK
               i_RST=Constant(0),
               i_D0=d[0], i_D1=d[1], i_D2=d[2], i_D3=d[3], i_D4=d[4], i_D5=d[5], i_D6=d[6],
               o_Q=out_q
           )

        #r = Constant(127, 8)
        #g = Constant(255, 8)
        #b = Constant(64, 8)
        tx0 = Cat(g[2], r[7], r[6], r[5], r[4], r[3], r[2])
        tx1 = Cat(b[3], b[2], g[7], g[6], g[5], g[4], g[3])
        tx2 = Cat(de, vs, hs, b[7], b[6], b[5], b[4])
        clk = Constant(0b1100011, 7) #pattern as per protocol, should not change!
        
        invert = [x in pn_swap for x in "012c"]
        xdr7(pads.tx0, tx0, invert=invert[0])
        xdr7(pads.tx1, tx1, invert=invert[1])
        xdr7(pads.tx2, tx2, invert=invert[2])
        xdr7(pads.clk, clk, invert=invert[3])

