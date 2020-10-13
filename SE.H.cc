// Declaration of the SE class - Security.
// Member functions defined in SE.cpp
// For reference only          

// preprocessor directives that
// prevent multiple inclusions of header file 

#ifndef SE_H  
#define SE_H 


class SE : public AI {   // Security = Internal rumination tasks

public:

	SE();
	~SE();

    void Sec();

private:

    void Rejuvinate();
    void PsiDecay();
    void Ego();
    
};

#endif   