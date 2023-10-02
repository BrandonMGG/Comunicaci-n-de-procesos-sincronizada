#include "sys/alt_irq.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

static int display1=64;
static int display2=64;
static int display3=64;
static int display4=64;
static int display5=64;

int suma=0;
int digit2=0;
int digit3=0;
int digit4=0;
int digit5=0;

static int run=0;

char hex_a[2];
char hex_b[2];
char hex_c[2];
char hex_d[2];
char hex_e[2];
char hex_final[9];

int exponente=0;
int modulo=0;
int sevensegChange=0;

int first=0;
int second=0;
int third=0;
int fourth=0;

int expModIndex=0;
int index=1;





int mod_pow(int base, int exp, int  mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return 666;
}
void actualizarDatos(){
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG0_BASE, display1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG1_BASE, display2);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG2_BASE, display3);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG3_BASE, display4);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG4_BASE, display5);
}
static void timer_isr()
{
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG0_BASE, display1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG1_BASE, display2);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG2_BASE, display3);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG3_BASE, display4);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG4_BASE, display5);

	if(!(IORD_ALTERA_AVALON_PIO_DATA(BTN_0_BASE) & 1)){
		sevensegChange= cambiarDisplay(sevensegChange);
		}
	if(sevensegChange==0 && !(IORD_ALTERA_AVALON_PIO_DATA(BTN_BASE) & 1) ){
		suma = sumarDisplay(suma);
		display1 = displayShow(suma,display1);
		}
	if(sevensegChange==1 && !(IORD_ALTERA_AVALON_PIO_DATA(BTN_BASE) & 1)){
		digit2 = sumarDisplay(digit2);
		display2 = displayShow(digit2,display2);

			}
	if(sevensegChange==2 && !(IORD_ALTERA_AVALON_PIO_DATA(BTN_BASE) & 1)){
		digit3 = sumarDisplay(digit3);
		display3 = displayShow(digit3,display3);

	}
	if(sevensegChange==3 && !(IORD_ALTERA_AVALON_PIO_DATA(BTN_BASE) & 1)){
		digit4 = sumarDisplay(digit4);
		display4 = displayShow(digit4,display4);

	}
	if(sevensegChange==4 && !(IORD_ALTERA_AVALON_PIO_DATA(BTN_BASE) & 1)){
		digit5 = sumarDisplay(digit5);
		display5 = displayShow(digit5,display5);

	}

    if(!(IORD_ALTERA_AVALON_PIO_DATA(BTN_1_BASE) & 1)){
    	exponente = suma+ digit2*16 + digit3*256 +digit4*4096 +digit5*65536;
    	resetData();
    }
    if(!(IORD_ALTERA_AVALON_PIO_DATA(BTN_2_BASE) & 1)){
    	modulo = suma+ digit2*16 + digit3*256 +digit4*4096 +digit5*65536;
    	resetData();
    }
    if((IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE) & 1)){
    	int number = 1;
    	int localIndex = 1;
    	int data[] = {18434, 4741, 11456, 11909, 6891, 18758, 4144, 10253, 5041, 4404, 6073, 13913, 16206, 6512};

    	//localIndex=index;
    	//int dato = data[0];
    	//int size = sizeof(data) / sizeof(data[0]);

    	    // Remove the first element from the array
    	//removeFirstElement(data, &size);
    	int dato=1;
    	if(index==0){
    		dato=data[0];
    	}
    	if(index==1){
    	    dato=data[1];
    	}
    	if(index==2){
    	    	    dato=data[2];
    	    	}
    	if(index==3){
    	    	    dato=data[3];
    	    	}
    	if(index==4){
    	    	    dato=data[4];
    	    	}
    	if(index==5){
    	    	    dato=data[5];
    	    	}
    	//int *ptr=data;
    	//number = mod_pow(data[i],exponente, modulo);
    	int result = 1;
    	int expTemp= exponente;
    	int base = dato;
    	int mod=modulo;
    	while (expTemp > 0) {
    		if (expTemp % 2 == 1) {
    			result = (result * base) % mod;
    	    }
    		base = (base * base) % mod;
    		expTemp /= 2;
    	}
    	number = result;
    	fourth = number % 10;
    	number /= 10;
    	third = number % 10;
    	number /= 10;
    	second = number % 10;
    	number /= 10;
    	first = number % 10;
    	suma=fourth;
    	display1 = displayShow(suma,display1);
    	digit2=third;
    	display2 = displayShow(digit2,display2);
    	digit3=second;
    	display3 = displayShow(digit3,display3);
    	digit4=first;
    	display4 = displayShow(digit4,display4);
    	digit5=0;
    	display5 = displayShow(digit5,display5);
    	//index= incrementarIndex(index);
    	index=incrementarIndex(index);
    }
    //unsigned int decimal_value = (unsigned int)strtol(hex_final, NULL, 16);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG0_BASE, display1);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG1_BASE, display2);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG2_BASE, display3);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG3_BASE, display4);
	IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG4_BASE, display5);
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}
int obtenerDato(int dataTmp[]){
	int dato=1;
	dato=dataTmp[index];
	return dato;
}
int incrementarIndex(int index){
	index+=1;
	return index;
}
int RSA(long long exponenteTmp, long long moduloTmp, long long data[])
{
    int size = sizeof(data) / sizeof(data[0]);
    long long valor_descencriptado = 1;
    for (int i = 0; i < 12 ; i++)
    {
        valor_descencriptado = mod_pow(data[i],exponenteTmp, moduloTmp);
    }
    return valor_descencriptado;
}


void resetData(){
	suma=0;
	digit2=0;
	digit3=0;
	digit4=0;
	digit5=0;
	display1=64;
	display2=64;
	display3=64;
	display4=64;
	display5=64;
}

int cambiarDisplay(int display_num){
	display_num+=1;
	if(display_num == 5){
		display_num=0;
	}
	return display_num;
}
int sumarDisplay(int sumaTmp){
	sumaTmp+=1;
	if(sumaTmp==16){
		sumaTmp=0;
	}
	return sumaTmp;
}
int displayShow(int suma1,int display){
	if (suma1 == 0) {
	    display = 64;
	} else if (suma1 == 1) {
	    display = 121;
	} else if (suma1 == 2) {
	    display = 36;
	} else if (suma1 == 3) {
	    display = 48;
	} else if (suma1 == 4) {
	    display = 25;
	} else if (suma1 == 5) {
	    display = 18;
	} else if (suma1 == 6) {
	    display = 2;
	} else if (suma1 == 7) {
	    display = 120;
	} else if (suma1 == 8) {
	    display = 0;
	} else if (suma1 == 9 ) {
	    display = 24;
	}else if (suma1 == 10 ) { //A
	    display = 8;
	}else if (suma1 == 11 ) { //B
	    display = 3;
	}else if (suma1 == 12 ) { //C
	    display = 70;
	}else if (suma1 == 13 ) { //D
	    display = 33;
	}else if (suma1 == 14 ) { //E
	    display = 6;
	}else if (suma1 == 15 ) { //F
	    display = 14;
	    suma1=0;
	}
	return display;
}

static void run_isr(void *context){
	(void) context;

	timer_isr();

}
int main(){
	alt_ic_isr_register(
		TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
		TIMER_0_IRQ,
		run_isr,
		NULL,
		NULL);
	IOWR_ALTERA_AVALON_TIMER_CONTROL(
		TIMER_0_BASE,
		ALTERA_AVALON_TIMER_CONTROL_ITO_MSK | ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);
	while (1);
}
