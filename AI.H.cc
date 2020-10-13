// Declaration of the AI class. 
// For reference only         
// Member functions defined in AI.cpp

// preprocessor directives that
// prevent multiple inclusions of header file
#ifndef AI_H  
#define AI_H 

#ifndef TFVAL  
#define TFVAL 
typedef int BOOL;
static BOOL True = 1;
static BOOL False = 0;
#endif

#ifndef ARY
#define ARY
#define ARYSIZ 100
#endif

#ifndef WRD
#define WRD
#define WRDSIZ 1000
#endif

class AI {

public:
   
   AI();          // Artificial Intelligence Constructor
   ~AI();         // Artificial Intelligence Deststructor

   void Alife();  // Artificial Intelligence Program

protected:
   
private:

};


class TH : public AI {   // Human input module with AI attention

public:

	TH();
	~TH();

    void Thn();

private:

    void Activate();
    void English();
    void NegSvo();   // Negative of Subject-Verb-Object
    void Svo();      // Subject Verb-Object
    
};   

class MO : public AI {   // Human input module with AI attention

public:

	MO();
	~MO();

    void Mot();

private:

};   

#endif