#include <sys/types.h>

/* Campos do protocolo invertidos para satisfazer big-endian */
struct dns_header {
	u_int16_t id;

	u_int16_t rd:1;
	u_int16_t tc:1;
	u_int16_t aa:1;
	u_int16_t opcode:4;
	u_int16_t qr:1;

	u_int16_t rcode:4;
	u_int16_t z:3;
	u_int16_t ra:1;

	u_int16_t arcount;
	u_int16_t nscount;
	u_int16_t ancount;
	u_int16_t qdcount;
};

struct dns_question {
	u_int16_t qclass;
	u_int16_t qtype;
};

struct dns_packet {
	struct dns_header header;
	char *data;
	u_int16_t data_size;
};

struct dns_response_packet {
	char *name;
	u_int16_t type;
	u_int16_t class;
	u_int32_t ttl;
	u_int16_t rdlength;
	char *rdata;
};
