//******************************************************************************
//  PWMDemo.c - Using Hardware Interrupts to Implement Pulse-Width Modulation
//  by Fourier Automation (davefer_work@hotmail.com)
//
//  Description: This program demonstrates the use of hardware interrupts
//  to trap a button click event AND to manage pulse-width modulation.
//
//  It is designed to run on the TI MSP430 Launchpad and utilize the button
//  on port 1.3, the LED at port 1.6 and the onboard clock.
//
//  On start, LED imitates ~50% power using Pulse-Width Modulation. On button
//  click, the power is bumped to higher level. There are 6 power levels
//  including off.
//
//  This demo was created by D. Ferreira and incorporates code snippets by 
//  M. Buccini, L. Westlund, and D. Dang all of Texas Instruments, Inc.
//******************************************************************************

#include  <msp430g2231.h>

int g_Clicks = 0;

enum _int{
  off=0,
  dim=5,
  low=15,
  medium=35,
  bright=60,
  full=100,
};

void Increment(enum _int* used){
  switch(*used){
    case off: *used = dim; break;
    case dim: *used = low; break;
    case low: *used = medium; break;
    case medium: *used = bright; break;
    case bright: *used = full; break;
    case full: *used = off; break;
  }
}


// Pulse-width modulation demo object
// PWIDemo g_PWI;
int g_iFrameWidth = 100;
enum _int g_iPulseWidth = medium;

//void PWIDemo();
void Increment(enum _int * used);

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
  // Button interrupt setup
  P1IE  |= BIT3; // P1.3 interrupt enabled
  P1IES |= BIT3; // P1.3 Hi/lo edge
  P1IFG &= ~BIT3; // P1.3 IFG cleared
  
  // Pulse-width modulation code
  P1DIR |= BIT6;                          // P1.6 output
  P1SEL |= BIT6;                          // P1.6 TA1/2 options
  CCR0 = 100;                             // PWM Period
  CCTL1 = OUTMOD_7;                       // CCR1 reset/set
  CCR1 = 50;                              // CCR1 PWM duty cycle
  TACTL = TASSEL_2 + MC_1;                // SMCLK, up mode

  _BIS_SR( LPM1_bits + GIE); // Enter LPM1 w/interrupt
}


// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
  P1IES ^= BIT3;
  P1IFG &= ~BIT3; // P1.3 IFG cleared

  if( g_Clicks > 0 ) // Button interrupts on down AND up. Let's manage that
  {                  // so that we only act once for each button press. 
    g_Clicks = 0;    // This must be the UP event. So let's reset our counter.
    Increment(&g_iPulseWidth);  // Increment the power level by one setting
    CCR1 = g_iPulseWidth;  // Task clock with new duty cycle.
  }
  else g_Clicks++;   // This must be the down click of the button.
}