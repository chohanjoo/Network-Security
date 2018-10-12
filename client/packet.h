
#ifndef PACKET_H_
#define PACKET_H_

#define MT_LOGIN_REQ 0x01
#define MT_LOGIN_ACK 0x02
#define MT_IMG_SEND 0X03
#define MT_IMG_ACK 0x04

#define R_SUCCESS 0x01
#define R_FAIL 0x00
#define MAX_ID_LEN 16
#define MAX_PWD_LEN 16
#define MAX_RESMSG_LEN 36

typedef struct packet_header{
	int msgType;
	int length;
} PACKET_HEADER;

typedef struct login_req{
	char id[MAX_ID_LEN];
	char passwd[MAX_PWD_LEN];
} LOGIN_REQ;

typedef struct login_ack{
	int result;
	char res_msg[MAX_RESMSG_LEN];
} LOGIN_ACK;

typedef struct img_send{
	int imgLength;
	unsigned char *img;
}IMG_SEND;

typedef struct img_ack{
	int imgResult;
	char res_msg[36];
}IMG_ACK;

void printPacketInformation(PACKET_HEADER *head, void *msg);

#endif /* PACKET_H_ */
