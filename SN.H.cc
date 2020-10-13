// Declaration of the SN class.
// Member functions defined in SN.cpp 
// For reference only             

// preprocessor directives that
// prevent multiple inclusions of header file 

#ifndef SN_H  
#define SN_H 

#define BUFLEN 80

class SN : public AI {   // Human input module with AI attention

public:

	SN();
	~SN();

    void Sen();

private:

    void Audition();
    int  AddWrdDb(char * tokenptr);
    void AddWrdDbList(char * tokenptr);
    void OldConcept();
    void NewConcept(int onset);
    BOOL AudRecog(char * tokenptr);
    void AudDamp();
    void RequestMsg();
    void ConvUpper();
    int  ClrSpc(int);
    void ClrActTags();
    void ClrBuf(); 
    void Parser();
    void Activate();
    int Find (const char * str, char * s) const;    
    char Buf[BUFLEN];
    
};   

#endif 