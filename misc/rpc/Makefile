.SUFFIXES:
.SUFFIXES: .c .o
LDLIBS = -lnsl -ltirpc
CLNT = llist
SRVR = llist_svc
CFLAGS = -g -Wall

RPCSRC = llist.x
RPCGEN = llist.h llist_clnt.c llist_svc.c llist_xdr.c

SRVR_OBJ = llist_svc_proc.o llist_xdr.o llist_svc.o
CLNT_OBJ = llist.o llist_xdr.o llist_clnt.o

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: $(RPCGEN) $(CLNT) $(SRVR)

$(CLNT): $(CLNT_OBJ)
	gcc $(LDLIBS) -o $(CLNT) $(CLNT_OBJ)

$(SRVR): $(SRVR_OBJ)
	gcc $(LDLIBS) -o $(SRVR) $(SRVR_OBJ)

$(RPCGEN): $(RPCSRC)
	rpcgen $(RPCSRC)

clean:
	@# Using the '@' sign suppresses echoing
	@# the line while the command is run
	rm -f $(CLNT) $(SRVR) $(RPCGEN)
