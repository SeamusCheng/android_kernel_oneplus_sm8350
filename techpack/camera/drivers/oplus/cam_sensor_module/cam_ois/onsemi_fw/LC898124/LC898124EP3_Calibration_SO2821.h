//********************************************************************************
//		<< LC898124 Evaluation Soft>>
//		Program Name	: LC898124EP3_Calibration_SO2821.h
// 		Explanation		: LC898124 calibration parameters 
//		Design			: K.abe
//		History			: First edition	
//********************************************************************************

// Version Name : 00-00-0000

// for	"SOXXXX"

//********************************************************************************
// defines
//********************************************************************************
#define		XY_BIAS			(0x80000000 )
#define		XY_OFST			(0x10000000 )

#ifdef	HALLADJ_FULLCURRENT
 #define 	MARGIN			(0x0400		)	// Margin
 #define 	BIAS_RANGE_XY 	(0x6400		)	// 40%	SO2821
 #define	SINE_OFFSET		(0x00074528 )	/* Freq * 80000000h / 18.0288kHz   : 4Hz */
 #define	SINE_GAIN		(0x7FFFFFFF	)	/*\93\FC\97\CDSine\94g\82̍ő\E5\93d\97\AC*/
#else	//HALLADJ_FULLCURRENT
 #define 	MARGIN			(0x1000		)	// VDD-Margin,GND-MARGIN
 #define 	BIAS_RANGE_XY	(0x8CCC		)	// 55%
 #define	SINE_OFFSET		(0x00074528 )	/* Freq * 80000000h / 18.0288kHz   : 4Hz */ 
 #define	SINE_GAIN		(0x4D780000	)	/*\93\FC\97\CDSine\94g\82̍ő\E5\93d\97\AC 115mA (115mA*7fff/190mA)  190mA(min) */
 
 
#if 0
 #define 	MARGIN_F		(0x0300		)	// Margin
 #define 	BIAS_RANGE_XY_F	(0xB332		)	// 70%
 #define	SINE_OFFSET_F	(0x00122CE4 )	/* Freq * 80000000h / 18.0288kHz   : 10Hz */
 #define	SINE_GAIN_F		(0x7FFFFFFF	)	/*\93\FC\97\CDSine\94g\82̍ő\E5\93d\97\AC*/
#endif
 
 
#endif	//HALLADJ_FULLCURRENT

#define 	ADJMARG			(0x0300		)	// Margin
#define 	DECRE_CAL		(0x0100		)	// decrease value

#define		SXGAIN_LOP		(0x30000000 )	// 0.375000
#define		SYGAIN_LOP		(0x30000000 )	// 0.375000

#define 	LOOP_NUM		(2508		)	// 18.0288kHz/0.130kHz*16times
#define 	LOOP_FREQ		(0x00D10422	)	// Freq * 80000000h / Fs
#define 	LOOP_GAIN		(0x09249249	)	// -22.92dB

#define 	LOOP_MAX_X		(SXGAIN_LOP << 1)	// x2
#define 	LOOP_MIN_X		(SXGAIN_LOP >> 1)	// x0.5
#define 	LOOP_MAX_Y		(SYGAIN_LOP << 1)	// x2
#define 	LOOP_MIN_Y		(SYGAIN_LOP >> 1)	// x0.5

#define		GAIN_GAP		(1000)			// 20*log(1000/1000)=0dB

#define		AF_DrvDir		0x01				// AF Drive output signal 0:Pos  1:Neg 
#define		AF_RRMD1_TM		0x4200				// to Macro  RRMD1
#define		AF_RRMD1_TI		0x4400				// to Infini RRMD1
#define		AF_Ft			0x00D9				/* Ft	fs/Freq	*/

#define		ACT_MAX_DRIVE_X		0x7FFFFFFF
#define		ACT_MAX_DRIVE_Y		0x7FFFFFFF
#define		ACT_MIN_DRIVE_X		0xD0000000
#define		ACT_MIN_DRIVE_Y		0xC0000000

#define		MAGNETIC_OFFSET_X	0x0890
#define		MAGNETIC_OFFSET_Y	0x0900

#define		Xch_Hall_MAX			4			//  4%
#define		Ych_Hall_MAX			3			//  3%
#define		Xch_Hall_MIN			0			//  0%
#define		Ych_Hall_MIN			0			//  0%

//********************************************************************************
// structure for calibration
//********************************************************************************
 const ADJ_HALL SO2821_HallCalParameter = { 
/* BiasInit */		XY_BIAS,
/* OffsetInit */	XY_OFST,
/* OffsetMargin */	MARGIN,
/* TargetRange */	BIAS_RANGE_XY,
/* TargetMax */		(BIAS_RANGE_XY + ADJMARG),
/* TargetMin */		(BIAS_RANGE_XY - ADJMARG),
/* SinNum */		(4500),				// 18.0288/0.004 > x
/* SinFreq */		SINE_OFFSET,
/* SinGain */		SINE_GAIN,
/* DecrementStep */ DECRE_CAL,
/* ActMaxDrive */	ACT_MAX_DRIVE_X,
/* ActMaxDrive */	ACT_MAX_DRIVE_Y,
/* ActMinDrive */	ACT_MIN_DRIVE_X,
/* ActMinDrive */	ACT_MIN_DRIVE_Y,
/* MagneticOff */	MAGNETIC_OFFSET_X,
/* MagneticOff */	MAGNETIC_OFFSET_Y,
/* HallMAX_X */		Xch_Hall_MAX,
/* HallMAX_Y */		Ych_Hall_MAX,
/* HallMIN_X */		Xch_Hall_MIN,
/* HallMIN_Y */		Ych_Hall_MIN,
}; //   

#if 0
 const ADJ_HALL SO2821_HallCalParameter_F = { 
/* BiasInit */		XY_BIAS,
/* OffsetInit */	XY_OFST,
/* OffsetMargin */	MARGIN_F,
/* TargetRange */	BIAS_RANGE_XY_F,
/* TargetMax */		(BIAS_RANGE_XY_F + ADJMARG),
/* TargetMin */		(BIAS_RANGE_XY_F - ADJMARG),
/* SinNum */		(1800),				// 18.0288/0.01 > x
/* SinFreq */		SINE_OFFSET_F,
/* SinGain */		SINE_GAIN_F,
/* DecrementStep */ DECRE_CAL,
}; //   
#endif

const ADJ_LOPGAN SO2821_LoopGainParameter = { 
/* Hxgain */		SXGAIN_LOP,
/* Hygain */		SYGAIN_LOP,
/* NoiseNum */		LOOP_NUM,
/* NoiseFreq */		LOOP_FREQ,
/* NoiseGain */		LOOP_GAIN, 
/* Gap  */			GAIN_GAP,
/* XJudgeHigh */ 	LOOP_MAX_X,
/* XJudgeLow  */ 	LOOP_MIN_X,
/* YJudgeHigh */ 	LOOP_MAX_Y,
/* YJudgeLow  */ 	LOOP_MIN_Y,
}; //   

 const AF_PARA SO2821_OpenAfParameter = { 
/* DriveDir*/		AF_DrvDir,
/* RRMD1 to Mcr*/	AF_RRMD1_TM,
/* RRMD1 to Inf*/	AF_RRMD1_TI,
/* resonance frq*/	AF_Ft,
}; //   

#undef	OFFSET_DIV
#undef	IME_OUT
#undef	BIAS_HLMT
#undef	BIAS_LLMT
#undef	XY_BIAS
#undef	XY_OFST
#undef	MARGIN
#undef	BIAS_RANGE_XY
#undef	SINE_OFFSET
#undef	SINE_GAIN
#undef	ADJMARG
#undef	DECRE_CAL

#undef	SXGAIN_LOP
#undef	SYGAIN_LOP
#undef	LOOP_NUM
#undef	LOOP_FREQ
#undef	LOOP_GAIN
#undef	GAIN_GAP
#undef	LOOP_MAX_X
#undef	LOOP_MIN_X
#undef	LOOP_MAX_Y
#undef	LOOP_MIN_Y

#undef	AF_DrvDir
#undef	AF_RRMD1_TM
#undef	AF_RRMD1_TI
#undef	AF_Ft

#undef	ACT_MAX_DRIVE_X
#undef	ACT_MAX_DRIVE_Y
#undef	ACT_MIN_DRIVE_X
#undef	ACT_MIN_DRIVE_Y

#undef	MAGNETIC_OFFSET_X
#undef	MAGNETIC_OFFSET_Y

#undef		Xch_Hall_MAX
#undef		Xch_Hall_MIN
#undef		Ych_Hall_MAX
#undef		Ych_Hall_MIN

