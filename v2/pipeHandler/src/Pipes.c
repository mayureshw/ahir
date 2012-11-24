#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <Pipes.h>

#define READ_BURST__(id, width, buf_len, buf) { uint32_t words_read = 0;\
	while(1)\
	{\
		words_read += read_from_pipe(id, width, buf_len - words_read, (void*) (buf + words_read));\
		if(words_read == buf_len)\
		break;\
		else\
		usleep(100);\
	} }

#define WRITE_BURST__(id, width, buf_len,buf) { uint32_t words_written = 0;\
	while(1)\
	{\
		words_written += write_to_pipe(id, width, buf_len - words_written, (void*) (buf + words_written));\
		if(words_written == buf_len)\
		break;\
		else\
		usleep(100);\
	} }

uint64_t read_uint64(const char *id)
{
	uint64_t ret_val;
	uint64_t* buf = &ret_val;
	READ_BURST__(id, 64, 1, buf);
	return(ret_val);
}

void write_uint64(const char *id, uint64_t data)
{
	uint64_t* buf = &data;
	WRITE_BURST__(id, 64, 1, buf);
}


// from pipe id, receive buf_len uint64_t's..
void read_uint64_n(const char *id, uint64_t* buf, int buf_len)
{
	READ_BURST__(id,64,buf_len,buf);
}

// to pipe id, send buf_len uint64_t's...
void write_uint64_n(const char *id, uint64_t* buf, int buf_len)
{
	WRITE_BURST__(id,64,buf_len,buf);
}

uint32_t read_uint32(const char *id)
{
	uint32_t ret_val;
	uint32_t* buf = &ret_val;
	READ_BURST__(id, 32, 1, buf);
	return(ret_val);
}
void write_uint32(const char *id, uint32_t data)
{
	uint32_t* buf = &data;
	WRITE_BURST__(id, 32, 1, buf);
}

// from pipe id, receive buf_len uint32_t's..
void read_uint32_n(const char *id, uint32_t* buf, int buf_len)
{
	READ_BURST__(id,32,buf_len,buf);
}

// to pipe id, send buf_len uint32_t's...
void write_uint32_n(const char *id, uint32_t* buf, int buf_len)
{
	WRITE_BURST__(id, 32, buf_len, buf);
}

uint16_t read_uint16(const char *id)
{
	uint16_t ret_val;
	uint16_t* buf = &ret_val;
	READ_BURST__(id, 16, 1, buf);
	return(ret_val);
}
void write_uint16(const char *id, uint16_t data)
{
	uint16_t* buf = &data;
	WRITE_BURST__(id, 16, 1, buf);
}

// from pipe id, receive buf_len uint16_t's..
void read_uint16_n(const char *id, uint16_t* buf, int buf_len)
{
	READ_BURST__(id,16,buf_len,buf);
}

// to pipe id, send buf_len uint16_t's...
void write_uint16_n(const char *id, uint16_t* buf, int buf_len)
{
	WRITE_BURST__(id, 16, buf_len, buf);
}

uint8_t read_uint8(const char *id)
{
	uint8_t ret_val;
	uint8_t* buf = &ret_val;
	READ_BURST__(id, 8, 1, buf);
	return(ret_val);
}
void write_uint8(const char *id, uint8_t data)
{
	uint8_t* buf = &data;
	WRITE_BURST__(id, 8, 1, buf);
}

// from pipe id, receive buf_len uint8_t's..
void read_uint8_n(const char *id, uint8_t* buf, int buf_len)
{
	READ_BURST__(id,8,buf_len,buf);
}

// to pipe id, send buf_len uint8_t's...
void write_uint8_n(const char *id, uint8_t* buf, int buf_len)
{
	WRITE_BURST__(id, 8, buf_len, buf);
}

uint32_t* read_uintptr(const char *id)
{
	return((uint32_t*) read_pointer(id));

}

void write_uintptr(const char *id, uint32_t* data)
{
	write_pointer(id, (void*) data);
}

void* read_pointer(const char *id)
{
  return((void*) read_uint32(id));
}
void write_pointer(const char *id, void* pdata)
{
	write_uint32(id, (uint32_t) pdata);
}

float read_float32(const char *id)
{
	float ret_val;
	float* buf = &ret_val;
	READ_BURST__(id, 32, 1, buf);
	return(ret_val);
}
void write_float32(const char *id, float data)
{
	float* buf = &data;
	WRITE_BURST__(id, 32, 1, buf);
}

void read_float32_n(const char *id, float* buf, int buf_len)
{
  read_uint32_n(id,(uint32_t*) buf,buf_len);
}

void write_float32_n(const char *id, float* buf, int buf_len)
{
  write_uint32_n(id, (uint32_t*) buf, buf_len);
}

double read_float64(const char *id)
{
	double ret_val;
	double* buf = &ret_val;
	READ_BURST__(id, 64, 1, buf);
	return(ret_val);
}
void write_float64(const char *id, double data)
{
	double* buf = &data;
	WRITE_BURST__(id, 64, 1, buf);
}
void read_float64_n(const char *id, double* buf, int buf_len)
{
  read_uint64_n(id,(uint64_t*) buf,buf_len);
}

void write_float64_n(const char *id, double* buf, int buf_len)
{
  write_uint64_n(id, (uint64_t*) buf, buf_len);
}

