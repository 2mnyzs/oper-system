#define ALARMTICKS(x) ((alt_ticks_per_second()*(x))/10)
#define QUANTUM_LENGTH 10;
#define MAX 500000;

#include <sys/alt_alarm.h>

void main(){
	prototype_os();
}

void prototype_os()
{
	//timer initialization
	static alt_alarm alarm;

	alt_alarm_start(&alarm, ALARMTICKS(5), myinterrupt_handler, NULL);

	while(1){
		alt_printf("This is my prototype_os.\n");
		//delay loop
		for(int j = 0;j< MAX;j++){

		}
	}
}

alt_u32 myinterrupt_handler(void* context){
	alt_printf("Interrupted by the timer!\n");
	return ALARMTICKS(QUANTUM_LENGTH);
}