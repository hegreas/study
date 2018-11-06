all : iRecv iSend
iRecv : receive.c
	gcc receive.c -o iRecv

iSend : send.c
	gcc send.c -o iSend

clean :
	rm -rf iSend iRecv
