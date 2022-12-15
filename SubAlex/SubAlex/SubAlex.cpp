#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define IP_L 4 /* 4 bytes -- length of ip adress storage var */
#define is_int(x) (x>='0' && x<='9')
#define MAXIMUM_OFFSET 7 /* 2^7 is 128 -- 1000 0000 */
#define SIZEOF_CHAR 8
#define MAXIMUM_BYTE 128 /*It's 2^MAXIMUM_OFFSET, you see */
#define t_char unsigned char

void print_binary (const t_char *c);
void usage (void);
t_char power_of_two (const t_char *c);
t_char *parse_ip (const char* ip_stor);
t_char *parse_subnet_mask (const t_char mask_stor);
t_char convert_single(const char *c);
int convert_room(const char *c);

int main(int argc, char** argv) {
  t_char i;
  if (argc!=5) { usage(); return 1; }
  
  t_char *ip=parse_ip(argv[1]);
  print_binary(ip);

  t_char *subnet_mask=parse_subnet_mask(ip[IP_L]);
  print_binary(subnet_mask);

  printf("Subnet mask is ");
  for (i=0; i<IP_L; i++)
    printf("%d.",subnet_mask[i]);
  printf("\n");

  printf("Subnet number %s is 2 in power of %d\n",argv[2], power_of_two(argv[2]));

  t_char subnet=convert_single(argv[3]);

  t_char mask_end=ip[IP_L]/SIZEOF_CHAR;
  t_char mask_offset=ip[IP_L]-(ip[IP_L]/SIZEOF_CHAR)*SIZEOF_CHAR;
  t_char subnet_bytes=power_of_two(argv[2]);
  if (SIZEOF_CHAR-mask_offset < subnet_bytes) {
    /* Подсеть не влезает, кладем в разные октеты */
    t_char subnet_l=0, subnet_r=0;
    subnet_l=subnet>>(subnet_bytes-(SIZEOF_CHAR-mask_offset));
    subnet_r=subnet<<(SIZEOF_CHAR-(subnet_bytes-(SIZEOF_CHAR-mask_offset)));

    ip[mask_end]=ip[mask_end] | subnet_l;
    ip[mask_end+1]=ip[mask_end+1] | subnet_r;
  }
  else {
    /* Ок, всё умещается в один октет */
    subnet=subnet<<(SIZEOF_CHAR-mask_offset-subnet_bytes);
    ip[mask_end]=ip[mask_end] | subnet;
}

  int room=convert_room(argv[4]);
  t_char room_bytes=power_of_two(argv[4])+1;
  mask_end=(ip[IP_L]+subnet_bytes)/SIZEOF_CHAR;
  printf("%d bits masked\n", mask_end*SIZEOF_CHAR+mask_offset+subnet_bytes);
  printf("Mask ends in %d byte\n",mask_end);
  printf("Room number consumes %d bits\n",room_bytes);
  printf("Free adress space is %d bits\n",((IP_L-mask_end)*SIZEOF_CHAR+(SIZEOF_CHAR-mask_offset-subnet_bytes)));
  if (room_bytes>((IP_L-mask_end)*SIZEOF_CHAR+(SIZEOF_CHAR-mask_offset-subnet_bytes))) {
    printf("Something does not fit! Please check your input\n");
    return 1;
  }

  if (room_bytes>SIZEOF_CHAR) {
    /* Разбитые октеты */
    t_char room_l=0, room_r=0;
    room_l=room>>(SIZEOF_CHAR-(room_bytes-SIZEOF_CHAR)+1);
    room_r=room;
    ip[mask_end]=ip[mask_end]|room_l;
    ip[mask_end+1]=ip[mask_end+1]|room_r;
  }
  else {
    /* Всё умещается в один октет */
    ip[IP_L-1]=ip[IP_L-1] | room;
  }
  print_binary(ip);
  
  printf("\nIp adress of given room is: ");
  for (i=0; i<IP_L; i++)
    printf("%d.",ip[i]);
  printf("\n");
  
  free(ip);
  free(subnet_mask);
  return 0;
}

void usage(void) {
  printf("Usage: xxx.xxx.xxx.xxx/xx number_of_subnets buildingsubnet room\n");
  printf("Please provide a valid ip adress pool and number of subnets\n");
}

void print_binary(const t_char *c)
{
  t_char i,j=0;
  for (; j<IP_L; j++) {
    for (i=MAXIMUM_BYTE; i>0; i/=2)
      if (c[j]&i) printf("1");
      else printf("0");
    printf(" ");
  }
  printf("\n");
}

t_char power_of_two (const t_char *c) {
  t_char i;
  int k=0;
  for(i=0; c[i]!='\0'; i++) 
    k=k*10+(c[i]-48);
  for (i=0; k>1; k/=2, i++);
  return i;
}

t_char *parse_ip (const char* ip_stor) {
  t_char *ip,i=0,j=0;
  ip=(t_char*) malloc(sizeof(t_char)*(IP_L+1));
  for (; i<IP_L+1; i++)
    ip[i]=0;
  for(i=0; ip_stor[i]!='\0'; i++) {
    if (is_int(ip_stor[i]))
      ip[j]=ip[j]*10+(ip_stor[i]-48);
    else
      j++;
  }
  return ip;
}

t_char *parse_subnet_mask (const t_char mask_stor) {
  t_char *subnet_mask,i;
  subnet_mask=(t_char*) malloc(sizeof(t_char)*(IP_L));
  for (i=0; i<IP_L; i++)
    subnet_mask[i]=0;
  for (i=0; i<mask_stor/SIZEOF_CHAR; i++)
    subnet_mask[i]=255;
  t_char mask_offset=mask_stor-(mask_stor/SIZEOF_CHAR)*SIZEOF_CHAR;
  for (i=MAXIMUM_BYTE; mask_offset>0; mask_offset--, i/=2)
    subnet_mask[mask_stor/SIZEOF_CHAR] = subnet_mask[mask_stor/SIZEOF_CHAR] | i;
  return subnet_mask;
}

t_char convert_single(const char *c) {
  t_char b=0,i;
  for(i=0; c[i]!='\0'; i++)
    if (is_int(c[i]))
      b=b*10+(c[i]-48);
  return b;
}  

int convert_room(const char *c) {
  int b=0;
  t_char i;
  for(i=0; c[i]!='\0'; i++)
    if (is_int(c[i]))
      b=b*10+(c[i]-48);
  return b;
}