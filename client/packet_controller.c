
#include "packet_controller.h"
#include "packet.h"
#include "codec.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int Packet_Handler(unsigned char *src, unsigned char **dst, int msgType, int *dst_len)
{
	LOGIN_ACK *loginAck;
	IMG_ACK *imgAck;
	IMG_SEND *imgSend;
	unsigned char *imgBuf;
	FILE *fp;
	int rv;


	switch(msgType){
	case MT_LOGIN_ACK:
		printf("\nClient received LOGIN_ACK packet.\n");
		decode_LoginAck(src, &loginAck);
		printf("\nLogin Result Msg: %s\n", loginAck->res_msg);
		free(loginAck);
				imgSend = (IMG_SEND *)calloc(1,sizeof(IMG_SEND));
				int fd = open("image.jpg",O_RDONLY);
				int imgLen;

				imgLen = lseek(fd,0,SEEK_END);
				imgSend->imgLength = imgLen;
				lseek(fd,0,SEEK_SET);
				
				imgSend->img = (unsigned char*)calloc(imgLen,sizeof(unsigned char));
				read(fd,imgSend->img,imgLen);
				close(fd);
				(*dst_len) = encode_packet(MT_IMG_SEND,(void *)imgSend,dst);

		rv = 0;
		break;

	case MT_IMG_ACK:
		printf("\nClient received IMG_ACK packet.\n");
		decode_ImgAck(src, &imgAck);
		printf("\nLogin Result Msg: %s\n", imgAck->res_msg);
		free(imgAck);
		rv = 0;
		break;
	default:
		rv = -1;
		break;
	}
	return rv;
}
