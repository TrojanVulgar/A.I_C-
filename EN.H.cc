********** EN.H file begins *************************************
// Declaration of the EN class. - EnBoot
// Member functions defined in EN.cpp 
// For reference only              
// CESARVERSATTI-!
// preprocessor directives that
// prevent multiple inclusions of header file 

#ifndef EN_H  
#define EN_H 


class EN : public AI {   // Initialization of AI arrays (fibers).

public:

	EN();
	~EN();

    void Ena();
    void Enb();
 

static void SetAudData(int t, int pho, int act, int pov,
                              int beg, int ctu, int psi);

static void SetPsiData(int t, int psi, int act, int jux, int pre, 
                              int pos, int seq, int enx);

static void SetEnData(int t, int nen, int act, int fex,
   				             int pos, int fin, int aud);
private:


};

#endif