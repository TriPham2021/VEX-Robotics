#pragma config(Sensor, port3,  EndX,           sensorVexIQ_Touch)
#pragma config(Sensor, port4,  EndY,           sensorVexIQ_Touch)
#pragma config(Motor,  motor2,          MotorX,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor5,          MotorY,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          MotorPen,      tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                       //
//   VEX-IQ-Plotter v3     (C) Andreas Dreier / Germany        Please don't hesitate to send me a mail   //
//                             andreas@dreier-privat.de        when you found errors or when you have    //
//   Plotter.VEXIQ.c           21.11.2015                      ideas for improvements ;-)                //
//                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                       //
//   Necessary parts:                                                                                    //
//                                                                                                       //
//   1 x Super Kit       --> http://www.vexrobotics.com/vexiq/products/kits-bundles/super-kit-eu.html    //
//       P/N: 228-3670                                                                                   //
//                                                                                                       //
//   2 x Gear Add-On kit --> http://www.vexrobotics.com/vexiq/products/accessories/228-2532.html         //
//       P/N: 228-2532                                                                                   //
//                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                       //
//   Connections to the VEX-IQ brain:                                                                    //
//                                                                                                       //
//   Port   Type           Function                                                                      //
//   ----   ------------   -------------------------------------------------------------------           //
//    02    Motor          Movement x axis                                                               //
//    03    Touch sensor   Detecting right limitation of x axis                                          //
//    04    Touch sensor   Detecting bottom limitation of y axis                                         //
//    05    Motor          Movement y axis                                                               //
//    06    Motor          Movement pen up and down                                                      //
//                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "plotBasics.inc"

///////////////////////////////////////////////////////////////////////////////////////////////////////////


float ms;
int   mx;
int   my;

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void plotLine( int px, int py )
{
     plotLineTo( mx + ms * px, my + ms * py );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void plotMove( int px, int py )
{
     plotMoveTo( mx + ms * px, my + ms * py );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void plotVEXIQ( int x, int y, float scale = 1.0 )
{
     ms = scale;
     mx = x;
     my = y;

     plotMove(    0,   99 );
     plotPenDown();
     plotLine(   78,    0 );
     plotLine(  115,    0 );
     plotLine(  194,   99 );
     plotLine(  158,   99 );
     plotLine(   97,   26 );
     plotLine(   40,   99 );
     plotLine(    0,   99 );
     plotPenUp();

     plotMove(  253,   31 );
     plotPenDown();
     plotLine(  312,   31 );
     plotLine(  316,   35 );
     plotLine(  318,   40 );
     plotLine(  319,   47 );
     plotLine(  318,   54 );
     plotLine(  314,   60 );
     plotLine(  228,   60 );
     plotLine(  225,   66 );
     plotLine(  222,   74 );
     plotLine(  224,   81 );
     plotLine(  227,   86 );
     plotLine(  311,   86 );
     plotLine(  316,   90 );
     plotLine(  319,   97 );
     plotLine(  318,  105 );
     plotLine(  315,  113 );
     plotLine(  230,  113 );
     plotLine(  222,  121 );
     plotLine(  223,  125 );
     plotLine(  223,  133 );
     plotLine(  227,  138 );
     plotLine(  311,  138 );
     plotLine(  317,  143 );
     plotLine(  319,  152 );
     plotLine(  318,  157 );
     plotLine(  313,  166 );
     plotLine(  228,  166 );
     plotLine(  215,  159 );
     plotLine(  209,  149 );
     plotLine(  206,  139 );
     plotLine(  205,  126 );
     plotLine(  206,  115 );
     plotLine(  207,  108 );
     plotLine(  214,  100 );
     plotLine(  206,   89 );
     plotLine(  205,   75 );
     plotLine(  205,   60 );
     plotLine(  211,   45 );
     plotLine(  218,   35 );
     plotLine(  227,   31 );
     plotLine(  263,   31 );
     plotPenUp();

     plotMove(  354,    0 );
     plotPenDown();
     plotLine(  375,    0 );
     plotLine(  425,   35 );
     plotLine(  472,    0 );
     plotLine(  517,    0 );
     plotLine(  450,   52 );
     plotLine(  513,   99 );
     plotLine(  471,   99 );
     plotLine(  426,   68 );
     plotLine(  379,   99 );
     plotLine(  334,   99 );
     plotLine(  399,   52 );
     plotLine(  329,    0 );
     plotLine(  356,    0 );
     plotPenUp();

     plotMove(  587,    0 );
     plotPenDown();
     plotLine(  750,    0 );
     plotLine(  754,    5 );
     plotLine(  755,   94 );
     plotLine(  752,   99 );
     plotLine(  561,   99 );
     plotLine(  554,   94 );
     plotLine(  555,    5 );
     plotLine(  562,    0 );
     plotLine(  597,    0 );
     plotPenUp();

     plotMove(  568,   16 );
     plotPenDown();
     plotLine(  602,   16 );
     plotLine(  609,   28 );
     plotLine(  598,   28 );
     plotLine(  618,   75 );
     plotLine(  628,   76 );
     plotLine(  631,   87 );
     plotLine(  595,   87 );
     plotLine(  592,   77 );
     plotLine(  601,   77 );
     plotLine(  582,   28 );
     plotLine(  571,   28 );
     plotLine(  568,   16 );
     plotPenUp();

     plotMove(  650,   15 );
     plotPenDown();
     plotLine(  695,   15 );
     plotLine(  701,   17 );
     plotLine(  707,   23 );
     plotLine(  713,   17 );
     plotLine(  725,   27 );
     plotLine(  720,   34 );
     plotLine(  732,   66 );
     plotLine(  735,   72 );
     plotLine(  733,   78 );
     plotLine(  730,   83 );
     plotLine(  723,   85 );
     plotLine(  712,   86 );
     plotLine(  662,   86 );
     plotLine(  653,   81 );
     plotLine(  647,   77 );
     plotLine(  642,   70 );
     plotLine(  628,   29 );
     plotLine(  630,   21 );
     plotLine(  635,   16 );
     plotLine(  641,   15 );
     plotLine(  650,   15 );
     plotPenUp();

     plotMove(  651,   45 );
     plotPenDown();
     plotLine(  651,   38 );
     plotLine(  655,   31 );
     plotLine(  695,   31 );
     plotLine(  681,   47 );
     plotLine(  690,   57 );
     plotLine(  706,   44 );
     plotLine(  714,   61 );
     plotLine(  711,   70 );
     plotLine(  704,   72 );
     plotLine(  669,   72 );
     plotLine(  663,   70 );
     plotLine(  659,   64 );
     plotLine(  650,   41 );
     plotPenUp();

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
     // Initialize the plotter

     plotInit();

     plotVEXIQ( 200, 200, 1.0 );

     // Move back to home position

     plotMoveHome();
}

//---------------------------------------------------------------------------------------------------------
//   Plotter.Minion.c    ---   End of program
//---------------------------------------------------------------------------------------------------------