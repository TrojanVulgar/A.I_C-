********** AI.CPP file begins ***********************************

// Member function definitions of the AI class.
// For reference only.                 


#include <iomanip.h>
#include <stdlib.h>
#include <ctype.h>

#include "AI.h"
#include "EN.h"
#include "SE.h"
#include "DB.h"
#include "SN.h"

   AI::AI()   // Constructor
   { 
   }
     
   AI::~AI()  // Destructor
   {
   }
  
   //  Classes below are AI derived classes
   
   MO::MO()        // Motorium class constructor
   {
   }              
   MO::~MO()       // Motorium class destructor
   {
   }
   void MO::Mot()  // Motorium
   {
   }  
   TH::TH()        // Think class constructor
   {
   }               // Think class destructor
   TH::~TH()
   {
   }
   void TH::Thn()  // Syntax and Vocabulary of Natural Language
   {
   }  

   void AI::Alife() 
   {
   DB DatBase;   		 // Create Data Base
   EN EngBoot;      	 // Create Initialize Data Base 
   SE Security;   	     // Create Internal Rumination
   SN Sensorium;  		 // Create Human Input Facility
   TH Think;        	 // Create Internal Associative Facility
   MO Motorium;   	     // Create Output Facility
   EngBoot.Ena();        // Initialize Word List
   EngBoot.Enb(); 		 // Initialize Word Data Base
   DatBase.StartupMsg(); // Display Startup Message
   while(True)
      {
      Security.Sec();     // AI Internal Rumination  
      Sensorium.Sen();    // AI Initial procesing of Input
      Think.Thn();        // AI Syntax and vocabulary of natural language
      Motorium.Mot();     // AI Output
      };
    }
 

 void main(void)
 {                                                                            
 AI AI1;      // Create Artificial Intelligence Program
 AI1.Alife(); // Execute Artificial Intelligence Program
 }                     