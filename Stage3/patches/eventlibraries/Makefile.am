AUTOMAKE_OPTIONS = foreign subdir-objects

if VXWORKS
include_HEADERS = oncsdefs.h \
  phenixTypes.h \
  EvtConstants.h \
  EvtStructures.h \
  oBuffer.h \
  EventTypes.h \
  BufferConstants.h

else
# all definitions

installedheaders = \
  generalDefinitions.h \
  event_io.h \
  ioselect.h \
  Event.h \
  A_Event.h \
  oncsEvent.h \
  oncsEvtConstants.h \
  oncsEvtStructures.h \
  oncsStructures.h \
  oncsSubConstants.h \
  oncsSubevent.h \
  EventTypes.h \
  Eventiterator.h \
  EvtConstants.h \
  EvtStructures.h \
  BufferConstants.h \
  phenixTypes.h \
  phenixOnline.h \
  testEventiterator.h \
  fileEventiterator.h \
  listEventiterator.h \
  dpipe_filter.h \
  buffer.h \
  simpleRandom.h \
  eventReceiverClient.h \
  gzbuffer.h \
  lzobuffer.h \
  bz2buffer.h \
  prdfBuffer.h \
  oBuffer.h \
  ophBuffer.h \
  ospBuffer.h \
  oEvent.h \
  ospEvent.h \
  ogzBuffer.h \
  olzoBuffer.h \
  oamlBuffer.h \
  oncsBuffer.h \
  oncsEventiterator.h \
  rcdaqEventiterator.h \
  packet.h \
  packetConstants.h \
  packet_hbd_fpgashort.h \
  packet_fvtx_dcm0.h \
  packet_w124.h \
  packet_A.h \
  packetPublic.h \
  packetV1Public.h \
  errorBlock.h \
  packetRoutines.h \
  decoding_routines.h \
  packetHeaders.h \
  Cpacket.h \
  packetHdr.h \
  packetHdrV1.h \
  formatError.h \
  dataBlock.h \
  framePackets.h \
  framePublic.h \
  frameV1Public.h \
  caen_correction.h \
  md5.h

allheaders = \
  ioselect.h \
  event_io.h \
  BoolDefs.h \
  devicedefs.h \
  oncsdefs.h \
  phenixOnline.h \
  phenixTypes.h \
  printmsg.h \
  Cframe.h \
  CframeV1.h \
  Cpacket.h \
  CpacketV1.h \
  dataBlock.h \
  dataBlockHdr.h \
  dataBlockPublic.h \
  errorBlock.h \
  fakeFrame.h \
  formatError.h \
  formatIO.h \
  frameHdr.h \
  frameHdrV1.h \
  framePackets.h \
  framePublic.h \
  frameRoutines.h \
  frameSourceIds.h \
  frameV1Public.h \
  packetHdr.h \
  packetHdrV1.h \
  packetPublic.h \
  packetRoutines.h \
  packetV1Public.h \
  A_Event.h \
  BufferConstants.h \
  Event.h \
  EventTypes.h \
  Eventiterator.h \
  EvtConstants.h \
  EvtStructures.h \
  simpleRandom.h \
  testEventiterator.h \
  fileEventiterator.h \
  listEventiterator.h \
  md5.h \
  PHmd5Utils.h \
  gen_utilities.h \
  dpipe_filter.h \
  PHmd5Value.h \
  buffer.h \
  prdfBuffer.h \
  decoding_routines.h \
  generalDefinitions.h \
  gzbuffer.h \
  lzobuffer.h \
  oBuffer.h \
  ophBuffer.h \
  ospBuffer.h \
  oEvent.h \
  ospEvent.h \
  ogzBuffer.h \
  olzoBuffer.h \
  oamlBuffer.h \
  oncsBuffer.h \
  oncsCollection.h \
  oncsEvent.h \
  oncsEventiterator.h \
  rcdaqEventiterator.h \
  oncsEvtConstants.h \
  oncsEvtStructures.h \
  oncsStructures.h \
  oncsSubConstants.h \
  oncsSub_id2evt.h \
  oncsSub_id4evt.h \
  oncsSub_idsis3300.h \
  oncsSub_idsis3300r.h \
  oncsSub_idcaenv792.h \
  oncsSub_idcaenv1742.h \
  oncsSub_idbspetdata.h \
  oncsSub_idrcpetdata.h \
  oncsSub_iduppetdata.h \
  oncsSub_iduppetdata_v104.h \
  oncsSub_iduppetparams.h \
  oncsSub_idsrs_v01.h \
  oncsSub_idfnalmwpc.h \
  oncsSub_idfnalmwpcv2.h \
  oncsSub_iddrs4v1.h \
  oncsSub_iddigitizerv1.h \
  oncsSub_idmvtxv0.h \
  oncsSub_idtpcfeev1.h \
  oncsSub_idtpcfeev2.h \
  oncsSub_idtpcfeev3.h \
  oncsSub_idtpcfeev4.h \
  oncsSub_idinttv0.h \
  oncsSub_iddreamv0.h \
  oncsSub_idmvtxv1.h \
  oncsSub_idmvtxv2.h \
  oncsSub_idmvtxv3.h \
  oncsSub_idgl1v0.h \
  oncsSub_idgl1v1.h \
  oncsSub_idh2gcroc3.h \
  oncsSubevent.h \
  packet.h \
  packetConstants.h \
  packetHeaders.h \
  packet_A.h \
  packet_collection.h \
  packet_gl1.h \
  packet_gl1p.h \
  packet_gl1_evclocks.h \
  packet_gl1psum.h \
  packet_id2evt.h \
  packet_id4evt.h \
  packet_id4scaler.h \
  packet_iddigitizerv2.h \
  packet_iddigitizerv3.h \
  packet_idll1v1.h \
  packet_idll1v2.h \
  packet_w124.h \
  packet_cdevpolarimeter.h \
  packet_cdevir.h \
  packet_cdevwcm.h \
  packet_cdevbpm.h \
  packet_cdevmadch.h \
  packet_cdevpoltarget.h \
  packet_starscaler.h \
  packet_hbd_fpga.h \
  packet_hbd_fpgashort.h \
  packet_fvtx_dcm0.h \
  packet_cdevring.h \
  packet_cdevringnopol.h \
  packet_cdevbuckets.h \
  packet_cdevdvm.h \
  caen_correction.h \
  mvtx_decoder/PayLoadCont.h

allsources = \
  Cframe.C \
  CframeV1.C \
  Cpacket.C \
  CpacketV1.C \
  dataBlock.C \
  errorBlock.C \
  fakeFrame.C \
  formatError.C \
  formatIO.C \
  framePackets.C \
  frameRoutines.C \
  packetRoutines.C \
  A_Event.cc \
  buffer.cc \
  prdfBuffer.cc \
  decoding_routines.cc \
  evt_mnemonic.cc \
  simpleRandom.cc \
  eventReceiverClient.cc \
  testEventiterator.cc \
  fileEventiterator.cc \
  listEventiterator.cc \
  md5.cc \
  PHmd5Utils.cc \
  PHmd5Value.cc \
  gzbuffer.cc \
  lzobuffer.cc \
  bz2buffer.cc \
  oEvent.cc \
  ospEvent.cc \
  oBuffer.cc \
  ophBuffer.cc \
  ogzBuffer.cc \
  olzoBuffer.cc \
  ospBuffer.cc \
  oamlBuffer.cc \
  oncsBuffer.cc \
  oncsEvent.cc \
  oncsEventiterator.cc \
  rcdaqEventiterator.cc \
  oncsSub_idcstr.cc \
  oncsSub_id2evt.cc \
  oncsSub_id4evt.cc \
  oncsSub_idsis3300.cc \
  oncsSub_idsis3300r.cc \
  oncsSub_idcaenv792.cc \
  oncsSub_idcaenv1742.cc \
  oncsSub_idbspetdata.cc \
  oncsSub_idrcpetdata.cc \
  oncsSub_iduppetdata.cc \
  oncsSub_iduppetdata_v104.cc \
  oncsSub_iduppetparams.cc \
  oncsSub_idsrs_v01.cc \
  oncsSub_idfnalmwpc.cc \
  oncsSub_idfnalmwpcv2.cc \
  oncsSub_iddrs4v1.cc \
  oncsSub_iddigitizerv1.cc \
  oncsSub_idmvtxv0.cc \
  oncsSub_idtpcfeev1.cc \
  oncsSub_idtpcfeev2.cc \
  oncsSub_idtpcfeev3.cc \
  oncsSub_idtpcfeev4.cc \
  oncsSub_idinttv0.cc \
  oncsSub_iddreamv0.cc \
  oncsSub_idmvtxv1.cc \
  oncsSub_idmvtxv2.cc \
  oncsSub_idmvtxv3.cc \
  oncsSub_idgl1v0.cc \
  oncsSub_idgl1v1.cc \
  oncsSub_idh2gcroc3.cc \
  oncsSubevent.cc \
  oncs_mnemonic.cc \
  packet_A.cc \
  packet_gl1.cc \
  packet_gl1p.cc \
  packet_gl1_evclocks.cc \
  packet_gl1psum.cc \
  packet_idcstr.cc \
  packet_id2evt.cc \
  packet_id4evt.cc \
  packet_id4scaler.cc \
  packet_iddigitizerv2.cc \
  packet_iddigitizerv3.cc \
  packet_idll1v1.cc \
  packet_idll1v2.cc \
  packet_mnemonic.cc \
  packet_w124.cc \
  packet_cdevpolarimeter.cc \
  packet_cdevir.cc \
  packet_cdevwcm.cc \
  packet_cdevbpm.cc \
  packet_cdevmadch.cc \
  packet_cdevpoltarget.cc \
  packet_starscaler.cc \
  packet_hbd_fpga.cc \
  packet_hbd_fpgashort.cc \
  packet_fvtx_dcm0.cc \
  packet_cdevring.cc \
  packet_cdevringnopol.cc \
  packet_cdevbuckets.cc \
  packet_cdevdvm.cc \
  caen_correction.cc \
  mvtx_decoder/InteractionRecord.cxx \
  mvtx_decoder/PayLoadCont.cxx \
  mvtx_decoder/PixelData.cxx \
  mvtx_decoder/GBTWord.cxx \
  mvtx_decoder/DecodingStat.cxx \
  mvtx_decoder/GBTLink.cxx

AM_LDFLAGS = -L$(libdir) -L$(ONLINE_MAIN)/lib -L$(OPT_SPHENIX)/lib

BUILT_SOURCES = ioselect.h


msgheaders = \
  msg_control.h \
  msg_profile.h \
  msg_buffer.h \
  date_filter_msg_buffer.h \
  filter_msg_buffer.h \
  remote_msg_buffer.h \
  strnstr.h

# FIXME we have to add $C_INCLUDE_PATH explicitly here! This will need to be changed
# upstream!
AM_CPPFLAGS =  -I$(includedir) -I$(C_INCLUDE_PATH) -I@ROOTINC@ -I$(OPT_SPHENIX)/include

noinst_HEADERS = \
  eventLinkDef.h \
  all.h

pkginclude_HEADERS = $(installedheaders) $(msgheaders)

if ! MAKEROOT6
  ROOT5_MSGDICTS = \
    msg_Dict.C
ROOT5_EVENTDICTS = \
    event_Dict.C
endif

CLEANFILES = \
  ioselect.h \
  event_Dict.C \
  event_Dict.h \
  setup.com \
  msg_Dict.C \
  msg_Dict.h

lib_LTLIBRARIES = \
  libmessage.la \
  libRootmessage.la \
  libNoRootEvent.la \
  libEvent.la

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  event_Dict_rdict.pcm \
  msg_Dict_rdict.pcm

bin_PROGRAMS = \
  dpipe \
  ddump \
  dlist \
  changeid \
  changehitformat \
  eventcombiner \
  prdf2prdf \
  prdfcheck \
  prdfsplit \
  eventServer \
  eventServer_classic \
  eventClient \
  lastEvent



dpipe_SOURCES = dpipe.cc
dlist_SOURCES = dlist.cc
ddump_SOURCES = ddump.cc
eventcombiner_SOURCES = eventcombiner.cc

if LINUX
dpipe_LDFLAGS = -Wl,-export-dynamic
endif

changeid_SOURCES = changeid.cc
changehitformat_SOURCES	= changehitformat.cc
prdf2prdf_SOURCES = prdf2prdf.cc
prdfcheck_SOURCES = prdfcheck.cc
prdfsplit_SOURCES = prdfsplit.cc
eventServer_SOURCES = eventServer.cc
eventServer_classic_SOURCES = eventServer_classic.cc
eventClient_SOURCES = eventClient.cc
lastEvent_SOURCES = lastEvent.cc


dpipe_LDADD = libNoRootEvent.la libmessage.la  -ldl
dlist_LDADD = libNoRootEvent.la libmessage.la  -ldl
ddump_LDADD = libNoRootEvent.la libmessage.la  -ldl
eventcombiner_LDADD = libNoRootEvent.la libmessage.la -ldl


changeid_LDADD = libNoRootEvent.la libmessage.la -ldl
changehitformat_LDADD = libNoRootEvent.la libmessage.la -ldl
prdf2prdf_LDADD = libNoRootEvent.la libmessage.la -ldl
prdfcheck_LDADD = libNoRootEvent.la -ldl
prdfsplit_LDADD = libNoRootEvent.la -ldl

eventServer_LDADD = libNoRootEvent.la -ldl -lpthread
eventServer_classic_LDADD = libNoRootEvent.la -ldl -lpthread
eventClient_LDADD = libNoRootEvent.la -ldl
lastEvent_LDADD = libNoRootEvent.la -ldl


libmessage_la_SOURCES = \
  date_filter_msg_buffer.cc \
  filter_msg_buffer.cc \
  remote_msg_buffer.cc \
  msg_buffer.cc \
  msg_control.cc \
  strnstr.cc


libEvent_la_SOURCES =  \
  $(ROOT5_EVENTDICTS)

libEvent_la_LIBADD = libNoRootEvent.la libRootmessage.la  @ROOTGLIBS@  -lz @LZOLIB@ -lbz2

libNoRootEvent_la_SOURCES = $(allsources)
libNoRootEvent_la_LIBADD = libmessage.la  -lz @LZOLIB@ -lbz2


# because this if statement contains dependencies, no more definitions after
# this

if NEWIO
ioselect.h:
	echo "// *** this is a generated file. Do not commit, do not edit" > ioselect.h
	echo "#ifndef __IOSELECT_H__" >> ioselect.h
	echo "#define __IOSELECT_H__" >> ioselect.h
	echo  >> ioselect.h
	echo "#define STREAMBUF_NEW_IOSTREAM" >> ioselect.h
	echo  >> ioselect.h
	echo "#endif" >> ioselect.h
else
ioselect.h:
	echo "// *** this is a generated file. Do not commit, do not edit" > ioselect.h
	echo "#ifndef __IOSELECT_H__" >> ioselect.h
	echo "#define __IOSELECT_H__" >> ioselect.h
	echo  >> ioselect.h
	echo "#endif" >> ioselect.h

endif

if LINUX

libRootmessage_la_SOURCES = \
  $(ROOT5_MSGDICTS)

#  msg_dict.C

msg_Dict.C : \
  ioselect.h \
  msg_control.h \
  date_filter_msg_buffer.h \
  filter_msg_buffer.h \
  remote_msg_buffer.h \
  msgLinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFS) $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

libRootmessage_la_LIBADD = libmessage.la

else

libRootmessage_la_SOURCES = \
  date_filter_msg_buffer.cc \
  filter_msg_buffer.cc \
  msg_buffer.cc \
  msg_control.cc \
  remote_msg_buffer.cc \
  strnstr.cc

endif



event_Dict.C : \
  ioselect.h \
  Event.h  \
  Eventiterator.h \
  fileEventiterator.h \
  listEventiterator.h \
  oncsEventiterator.h \
  rcdaqEventiterator.h \
  packet.h \
  testEventiterator.h \
  eventReceiverClient.h \
  eventLinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFS) $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^


%_Dict.C: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

# get the dependency for the pcm files
%_Dict_rdict.pcm: %_Dict.C ;


# clean cache dir on Solaris 5.8
clean-local:
	rm -rf SunWS_cache
	rm -f *Dict* $(BUILT_SOURCES) *.pcm

#if VXWORKS
endif
