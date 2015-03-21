

#include "system.h"
#include "altera_avalon_pio_regs.h"

#define LEFTSHIFT 0
#define LEFTMASK (0x1<<LEFTSHIFT)
#define RIGHTSHIFT 1
#define RIGHTMASK (0x1<<RIGHTSHIFT)

#define LEFTSTEP 1
#define RIGHTSTEP 3
#define LEFTDIR 0
#define RIGHTDIR 2

#define LEFTPOL 0x1
#define RIGHTPOL 0x0


static short MicroStep = 0;
static int delay2 = 10000;
static int delay =  10000;

static int db_vec(int state, int dir, int ms) {
	int DB_vec = 0;
	DB_vec =
			(((state & LEFTMASK)>>LEFTSHIFT)<<LEFTSTEP) |
			(((state & RIGHTMASK)>>RIGHTSHIFT)<<RIGHTSTEP) |
			((((dir & LEFTMASK)>>LEFTSHIFT)^LEFTPOL)<<LEFTDIR) |
			((((dir & RIGHTMASK)>>RIGHTSHIFT)^RIGHTPOL)<<RIGHTDIR) ;
	return DB_vec;
}

void init_DB() {
	MicroStep = 0x0;

	IOWR_ALTERA_AVALON_PIO_DATA(DRAWBOT_BASE,db_vec(0x0,0x0,MicroStep));
	IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,0x01);
}

void move_DB(int left, int right) {
	int i;
	int step_dir = 0;
	if (left > 0) {
		if (!(step_dir & LEFTMASK)) step_dir |= LEFTMASK;
	} else if (left < 0) {
		if (step_dir & LEFTMASK) step_dir |= LEFTMASK;
	}
	if (right > 0) {
		if (!(step_dir & RIGHTMASK)) step_dir |= RIGHTMASK;
	} else if (right < 0) {
		if (step_dir & RIGHTMASK) step_dir |= RIGHTMASK;
	}
	int vec = db_vec(0x0,step_dir,MicroStep);
	IOWR_ALTERA_AVALON_PIO_DATA(DRAWBOT_BASE,vec);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,vec);

	for (i = 0; i < delay2; i++);

	int step_state = 0x0;

	if (left)  step_state |= LEFTMASK;
	if (right) step_state |= RIGHTMASK;

	vec = db_vec(step_state,step_dir,MicroStep);
	IOWR_ALTERA_AVALON_PIO_DATA(DRAWBOT_BASE,vec);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,vec);
	for (i = 0; i < delay; i++);
}
