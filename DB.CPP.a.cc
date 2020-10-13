********* DB.CPP file begins ***********************************
// Member function definitions of the DB class.
// For reference only.                  

// Data Base - Creates and manipulates AI
// memory arrays. Currently 1 dimensional
// fixed length. Should be variable length
// and a linked list to allow convenient
// insertion and deletion. Deletion 
// currently just clears the location.
// Should also be asociative memory.
// Hashing would help.


#include <iomanip.h>

#include "AI.h"   
#include "DB.h"

   int Time;              // Time index to words

   PsiStr * PsiAryPtr;    // Pointer to start of Psi array (fiber).
   EnStr  * EnAryPtr;     // Pointer to start of En array (fiber).
   AudStr * AudAryPtr;    // Pointer to start of Aud array (fiber).
   char   * WrdAryPtr;    // Pointer to start of Word list.
   
   DB::DB()
   {
   // Use extensible Array class here
   // rather than fixed size array
   if((PsiAryPtr = new PsiStr[ARYSIZ]) == (PsiStr *)0)
       PrintMemErr();
   if((EnAryPtr  = new EnStr[ARYSIZ]) == (EnStr *)0)
       PrintMemErr();
   if((AudAryPtr = new AudStr[ARYSIZ]) == (AudStr *)0)
       PrintMemErr(); 
   ClrPsi();   // Clears Psi array (Tabulrasa equivalent)                     
   ClrEn();    // Clears En  array (Tabulrasa equivalent)                    
   ClrAud();   // Clears Aud array (Tabulrasa equivalent)                     
   if((WrdAryPtr = new char[WRDSIZ]) == (char *)0)
       PrintMemErr();
   ClrWrd(); // Clears Word List
   }
   
   DB::~DB()
   {
   delete [] PsiAryPtr;
   delete [] EnAryPtr;
   delete [] AudAryPtr;
   delete [] WrdAryPtr;
   }
        
   PsiStr * DB::GetPsiAryPtr()   // Get Psi beginning pointer
   {
   return(PsiAryPtr);
   }

   EnStr * DB::GetEnAryPtr()     // Get En beginning pointer
   {
   return(EnAryPtr);
   }

   AudStr * DB::GetAudAryPtr()   // Get Aud beginning pointer
   {
   return(AudAryPtr);
   }

   char * DB::GetWrdPtr()        // Get word list beginning pointer
   {
   return(WrdAryPtr);
   }
   
   void DB::PrintMemErr()        // Memory error message
   {
   cout << "\nArray creation error\n";
   }
   
   // Set functions
   // Templates to be used for data base functions
   
    BOOL DB::SetEle(PsiStr * StrPtr, const int EleIdx)    // Set concept array element
   	{                                                     // This is the Instantiate module
   	(PsiAryPtr+EleIdx)->psi = StrPtr->psi;
   	(PsiAryPtr+EleIdx)->act = StrPtr->act;
   	(PsiAryPtr+EleIdx)->jux = StrPtr->jux;
  	(PsiAryPtr+EleIdx)->pre = StrPtr->pre;
   	(PsiAryPtr+EleIdx)->pos = StrPtr->pos;
   	(PsiAryPtr+EleIdx)->seq = StrPtr->seq;
   	(PsiAryPtr+EleIdx)->enx = StrPtr->enx; 
    return(True);
   	}
 				
   BOOL DB::SetEle(EnStr  * StrPtr, const int EleIdx)   // set english lexicon element, element index
   	{                                                   // This is the EnVocab module
   	(EnAryPtr+EleIdx)->nen = StrPtr->nen;              
   	(EnAryPtr+EleIdx)->act = StrPtr->act;
   	(EnAryPtr+EleIdx)->fex = StrPtr->fex;
  	(EnAryPtr+EleIdx)->pos = StrPtr->pos;
   	(EnAryPtr+EleIdx)->fin = StrPtr->fin;
   	(EnAryPtr+EleIdx)->aud = StrPtr->aud;
    return(True);
   	}

   BOOL DB::SetEle(AudStr * StrPtr, const int EleIdx)   // set auditory memory element, element index
   	{
   	(AudAryPtr+EleIdx)->pho = StrPtr->pho;
   	(AudAryPtr+EleIdx)->act = StrPtr->act;
   	(AudAryPtr+EleIdx)->pov = StrPtr->pov;
  	(AudAryPtr+EleIdx)->beg = StrPtr->beg;
   	(AudAryPtr+EleIdx)->ctu = StrPtr->ctu;
   	(AudAryPtr+EleIdx)->psi = StrPtr->psi;
    return(True);
   	}

   // get functions 
   
   PsiStr * DB::GetPsiEle( const int EleIdx)   // return concept array element 
   	{
   	return(GetPsiAryPtr() + EleIdx);
   	}
   	
   EnStr * DB::GetEnEle( const int EleIdx)   // return english lexicon element
   	{
   	return(GetEnAryPtr() + EleIdx);
   	} 

   AudStr * DB::GetAudEle( const int EleIdx)   // return auditory memory element
   	{
   	return(GetAudAryPtr() + EleIdx);
   	}

   // delete functions
   
   BOOL DB::DelPsi( const int EleIdx); // delete concept array element, element index
   BOOL DB::DelEn(  const int EleIdx); // delete english lexicon element, element index
   BOOL DB::DelAud( const int EleIdx); // delete auditory memory element, element index
   
   // print functions 
   
   BOOL DB::PrintPsiElements();  // output
   BOOL DB::PrintEnElements();   // output 
   BOOL DB::PrintAudElements();  // output
   
   BOOL DB::SetTime(int t)       // Set Time
   {
   if((t < 65000) && (t >= 0))
       {
       Time = t;
       return(True);
       }
   else
   	   return(False);
   }
                                 
   int DB::GetTime()             // Get Time
   {
   return(Time);
   }

   void DB::StartupMsg()
   {
   cout << "\nThis software is not waranteed to perform any function.\n" << endl;
   }


 
   void DB::ClrPsi()    // Clears Psi array (Tabulrasa equivalent)  
   {
   int i;
   PsiStr PsiZer;
   PsiStr * PsiZerPtr = & PsiZer; 
   PsiZer.psi = 0;
   PsiZer.act = 0;
   PsiZer.jux = 0;
   PsiZer.pre = 0;
   PsiZer.pos = 0;
   PsiZer.seq = 0;
   PsiZer.enx = 0;
   for( i=0;i<ARYSIZ;i++)
   		DB::SetEle(PsiZerPtr,i);		    ; 
   }
   
   void DB::ClrEn()     // Clears En array (Tabulrasa equivalent)  
   {
   int i;
   EnStr EnZer;
   EnStr * EnZerPtr = & EnZer; 
   EnZer.nen = 0;
   EnZer.act = 0;
   EnZer.fex = 0;
   EnZer.pos = 0;
   EnZer.fin = 0;
   EnZer.aud = 0; 
   for( i=0;i<ARYSIZ;i++)
   		DB::SetEle(EnZerPtr,i);		    
   }
   
   void DB::ClrAud()   // Clears Aud array (Tabulrasa equivalent)  
   {
   int i;
   AudStr AudZer;
   AudStr * AudZerPtr = & AudZer; 
   AudZer.pho = ' ';
   AudZer.act = 0;
   AudZer.pov = 0;
   AudZer.beg = 0;
   AudZer.ctu = 0;
   AudZer.psi = 0; 
   for( i=0;i<ARYSIZ;i++)
   		DB::SetEle(AudZerPtr,i);		    ; 
   } 
   
   void DB::ClrWrd()     // Clears word list  
   {
   int i;
   for(i=0;i<WRDSIZ;i++)
   		*(WrdAryPtr + i) = ' ';
   }

****************************** DB.CPP file ends *****************
EN.H
AI.H
SN.H
SE.H
DB.H
AI.CPP
SE.CPP
EN.CPP
DB.CPP
SN.CPP
********** SN.CPP file begins ***********************************

// Member function definitions of the SN class.
// Sensorium - For reference only.    9/16/03


#include <iomanip.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>

#include "AI.h"   
#include "SN.h"
#include "DB.h"
#include "EN.h" 
  

   SN::SN()        // Sensorium class constructor
   {
   }               // Sensorium class destructor
   SN::~SN()
   {
   }

   void SN::Sen()  // Human input module with AI attention
   {
   RequestMsg();   // Get Human Input
   ClrActTags();   // Clear Active Tags
   Audition();     // Process Human Input
   } 

   void SN::RequestMsg()   // Get Human Input
   {
   cout << "Enter a brief positive or negative unpunctuated sentence." << endl;
   cout << "The AI listens for an input, and then generates a thought.\n" << endl;
   cout << "Enter an * to exit the AI.\n" << endl;
   cout << "Human: "; 
   ClrBuf();
   cin.getline(Buf,BUFLEN,'\n');
   }
   
   void SN::ClrActTags()
   {
   AudStr * AudPtr;
   int t = DB::GetTime();
   for (int i = 0;iact = 0;
        }
   }
   
   void SN::Audition()  // AI attention
   {
   int idx = 0;
   int onset; // Beginning of word
   char * tokenptr;  
   if(Buf[0] == '*')    // If first character is * then exit program
      {
      cout << "\nUser Halt.\n" << endl;
      exit(0);
      }
   ConvUpper();         // Convert all characters in message to upper case   
   idx = ClrSpc(idx);   // Skip any leading spaces in messge
   
   // Process words and characters by propagating effect of old
   // words into Psi data base and adding new words and propagating
   // their presence into the Psi data base. 
   
   tokenptr = strtok(Buf," ");
   tokenptr = tokenptr + idx; // Adjust pointer to skip leading spaces
   while(tokenptr != NULL)    // Extract words
   		 {
   		 cout << tokenptr << endl;
         if(AudRecog(tokenptr)) // Test for word in data base list
   				{
   				OldConcept();  // Word is in data base so update concept
   				} 
   		    else
   				{   
   				onset = AddWrdDb(tokenptr); // Add word to data base and return start time
   				AddWrdDbList(tokenptr); // Add word to data base list
   				NewConcept(onset);           // Update concept of new word
   				}
          tokenptr = strtok(NULL, " "); 
          }
   }
   
// Find the index to the first character of the 
// character string str embedded in the character
// string s.

    int SN::Find (const char * str, char * s) const
	{
	char * s2 = strstr(s,str);
	if (s2) 
	   return (s2 - s);
	else
	   return(-1);
    }

   void SN::ClrBuf()    // Clear the input buffer
   {
    int i = 0;
    for(i=0;i<BUFLEN;i++)
        Buf[i] = NULL;
    }

   
   void SN::ConvUpper()    // Convert input to upper case
   {
   for(int i =0;i<BUFLEN;i++)
      Buf[i] = (char) toupper(Buf[i]);
   }

   int SN::ClrSpc(int i)  // Find index for first non space character
   {
   while(Buf[i] == ' ')
       {
       i++;
       }            
   return(i);
   }

   BOOL SN::AudRecog(char * tokenptr)  // Test for word in data data base list
   { 
   int i,len;
   char * Wrd;
   Wrd = DB::GetWrdPtr();
   i = SN::Find(tokenptr,Wrd);
   if(i<0) 
       return(False);
   if(*(Wrd + i - 1) != ' ')     
       return(False);
   len = strlen(tokenptr);
   if(*(Wrd + i + len) != ' ')
       return(False);
   return(True);
   }

   
   void SN::OldConcept()   // Update arrays (fibers) for existing word (concept)
   {
   SN::Parser();
   SN::Activate();
   }
   
   void SN::NewConcept(int onset)   // Update arrays (fibers) for new  word (concept)
   {
   int t;
   t = DB::GetTime();
   EN::SetPsiData(t,1,31,0,0,5,0,1);      
   EN::SetEnData(t,1,31,1,5,1,onset);    
   }
   
   void SN::Parser()
   {
   }
   
   void SN::Activate()
   {
   }              
  
   
   int SN::AddWrdDb(char * tokenptr)  // Add a word to the Aud array (fiber).
	{
	int t,i,wrdlen,onset;
    wrdlen = strlen(tokenptr);  		
    t = DB::GetTime();
   	t = t + 2;  // Leave blank in data base and set time for new word start 
   	onset = t;  // Save the new word start time
   	EN::SetAudData(t,*(tokenptr),0,35,1,0,0);  // Set first letter
    if(wrdlen >= 1)
   		{
   		for(i=1;i<wrdlen;i++)
   			{
   		    EN::SetAudData(t,*(tokenptr+i),0,35,0,1,0);
   		    t++;
   		    }
   		DB::SetTime(t);
   		}
   	return(onset);
   	}			
 
    void SN::AddWrdDbList(char * tokenptr)  // Add a word to the word search list
	{;
    char * WrdList;
    WrdList = DB::GetWrdPtr();
    strcat(WrdList,tokenptr);
    strcat(WrdList," ");
   	}			