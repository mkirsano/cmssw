#ifndef DataFormats_SiPixelRawDataError_h
#define DataFormats_SiPixelRawDataError_h

//---------------------------------------------------------------------------
//!  \class SiPixelRawDataError
//!  \brief Pixel error -- collection of errors and error information
//!
//!  Class to contain and store all information about errors
//!  
//!
//!  \author Andrew York, University of Tennessee
//---------------------------------------------------------------------------

#include <string>

class SiPixelRawDataError {
  public:

    /// Default constructor
    SiPixelRawDataError();
    /// Constructor with 32-bit error word and type included
    SiPixelRawDataError(const unsigned int errorWord32, const int errorType);
    /// Constructor with 64-bit error word and type included (header or trailer word)
    SiPixelRawDataError(const long long errorWord64, const int errorType);
    /// Destructor
    ~SiPixelRawDataError();

    void setWord32(unsigned int errorWord32);		// function to allow user to input the error word (if 32-bit) after instantiation
    void setWord64(long long errorWord64);		// function to allow user to input the error word (if 64-bit) after instantiation
    void setType(int errorType);			// function to allow user to input the error type after instantiation

    inline unsigned int getWord32() const {return errorWord32_;} // the 32-bit word that contains the error information
    inline unsigned int getWord64() const {return errorWord64_;} // the 64-bit word that contains the error information
    inline int getType() const {return errorType_;} 	         // the number associated with the error type (26-31 for ROC number errors, 32-33 for calibration errors)
    inline std::string getMessage() const {return errorMessage_;}     // the error message to be displayed with the error	
                                                                
  private:

    unsigned int errorWord32_;
    long long errorWord64_;
    int errorType_;
    std::string errorMessage_;
    
    void setMessage(int errorType);				 // function to create an error message based on errorType
    
};

#endif
