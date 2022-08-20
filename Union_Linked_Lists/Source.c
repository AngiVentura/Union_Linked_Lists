#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "md5.h" //using void md5String(const char* input, char* output);
#include "md4.h" //using void md4String(const char* input, char* output);

#define MD4_HASH 0
#define MD5_HASH 1
#define True 1
#define False 0
typedef unsigned char HashType;
typedef unsigned char Byte;
typedef char Bool;
void md5String(const char* input, char* output);
void md4String(const char* input, char* output);
void print_hash(const unsigned char* p);
typedef struct msgWithHash
{
	unsigned int id;
	char* text;
	union
	{
		Byte md4[16];
		Byte md5[16];
	} hashDigest;
	HashType type;
}msgWithHash;

typedef struct msgListNode msgListNode;
struct msgListNode
{
	msgWithHash* data;
	msgListNode* next;
};

void print_hash(const unsigned char* p);
msgWithHash* createMessage(unsigned int id, const char* text, HashType type);
void printMessage(const msgWithHash* message);
msgListNode* addMessage(msgListNode* head, msgWithHash* data);
int findMsgByHashIterative(const msgListNode* head, Byte hash[16]);
int findMsgByHashRecursive(const msgListNode* head, Byte hash[16]);
msgListNode* deleteMessage(msgListNode* head, unsigned int id);
Bool verifyIntegrity(msgListNode* head, unsigned int id, Byte compareHash[16]);
msgListNode* reverseMsgList(msgListNode* head);
void freeMsgList(msgListNode* head);

int main() {

	/******************** Example 1 from PDF ********************************************/

	msgWithHash y;
	y.id = 154224;
	y.text = "this is some text thet i want to hash";
	y.hashDigest.md4;
	y.type = 1;
	printf("message id: %d\n", y.id);
	printf("message text: %s\n", y.text);
	if (y.type != NULL) {
		if (y.type == (MD4_HASH || MD5_HASH))
		{
			if (y.type == MD4_HASH)
			{
				printf("md4 HASH: ");
				md4String(y.text, y.hashDigest.md4);
				print_hash(y.hashDigest.md4);
			}
			else {
				printf("md5 HASH: ");
				md5String(y.text, y.hashDigest.md5);
				print_hash(y.hashDigest.md5);
			}
		}
	}

	return 0;



	/*const char* sentence = "this is some text that I want to hash.";
	printf("text: \"%s\"\n", sentence);
	unsigned char hash[16] = { 0 };
	md5String(sentence, hash);
	printf("md5: ");
	print_hash(hash);

	printf("md4: ");
	md4String(sentence, hash);
	print_hash(hash);*/

	/******************** Example 2 from PDF ********************************************/

	/*const msgWithHash* msg1 = createMessage(87651233, "", MD4_HASH);
	const msgWithHash* msg2 = createMessage(3, "banana1", MD5_HASH);
	const msgWithHash* msg3 = createMessage(275, "banana2!", MD4_HASH);
	const msgWithHash* msg4 = createMessage(342234, "Hello World", MD4_HASH);

	printMessage(msg1);
	printMessage(msg2);
	printMessage(msg3);
	printMessage(msg4);*/

}

void print_hash(const unsigned char* p) {
	for (unsigned int i = 0; i < 16; ++i) {
		printf("%02x", p[i]);
	}
	printf("\n");
}






/// <summary>
/// ////
/// </summary>


//#include <stdio.h>
//
//typedef struct ProtocolBits
//{
//	unsigned char b02 : 3;
//	unsigned char b37 : 5;
//}ProtocolBits;
//
//typedef union Packet
//{
//	unsigned char data;
//	ProtocolBits bits;
//} Packet;
//
//void main()
//{
//	Packet myPacket;
//	myPacket.data = 0b11001010;
//	if (myPacket.bits.b02)
//		printf("banana\n");
//}




//
//typedef union example
//{
//	char c;
//	short s;
//	int n;
//	double d;
//} example;
//
//
//void main()
//{
//	example myUnion;
//	myUnion.d = 1;
//	myUnion.c = 0xff;
//	myUnion.s = 0x1234;
//	myUnion.n = 0x5678abcd;
//}







//#include <stdio.h>
//
//typedef struct fruit
//{
//	float price;
//	char name[30];
//	char color[30];
//} Fruit;
//
//typedef union testUnion
//{
//	int x;
//	char y[4];
//} testUnion;
//
//void main()
//{
//	struct fruit yellowBanana = {5.66, "yellow banana", "yellow"};
//	Fruit apple = {12.50, "apple", "green"};
//
//	testUnion myUnion;
//	myUnion.x = 0x01020304;
//	if (myUnion.y[1] == (char)3)
//		printf("awesome");
//	
//	yellowBanana.price = 15;
//
//}