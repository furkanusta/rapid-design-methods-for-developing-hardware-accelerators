// See LICENSE for license details.
/*[[[cog
     import cog
     from cog_acctempl import *
     from dut_params import dut
     if "thread_nm" not in globals():
       lst = cog.previous.lstrip('/').rstrip('\n').split('=')
       assert( lst[0]=="thread_nm")
       assert( len(lst)==2)
       global thread_nm
       thread_nm = lst[1]
     cog.outl( "//thread_nm=" + thread_nm)
  ]]]*/
//thread_nm=ina_addr_gen
//[[[end]]] (checksum: a4b1642c786232a5ccf3e77e4575e922)

// Declare helper methods and class variables

/*[[[cog
     c = dut.get_cthread(thread_nm)
     cog.outl("void %s() {" % (c.nm,))
     for p in c.ports:
       cog.outl("  %s; // type: %s" % (p.reset,p.type(dut)))
  ]]]*/
void ina_addr_gen() {
  inaReqOut.reset_put(); // type: MemTypedReadReqType<Blk>
//[[[end]]] (checksum: abaf039f7b6d0718f0050363c9eb37fe)

  bool already_sent = false;

  /*[[[cog
       if c.writes_to_done:
         cog.outl("done = false;")
    ]]]*/
  //[[[end]]] (checksum: d41d8cd98f00b204e9800998ecf8427e)
  wait();
  while (1) {
    if ( start) {

      if ( !already_sent) {
        inaReqOut.put( MemTypedReadReqType<Blk>( config.read().getInaAddr( 0), config.read().get_n() >> 4));
        already_sent = true;
      }

    }
    wait();
  }
}