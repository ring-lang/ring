#define RINGHTTPLIB_RINGCODESIZE 512
#define RINGHTTPLIB_MAXRINGCODE  511
#define RINGHTTPLIB_ERRORINCODESIZE "The string that contains Ring code is larger than expected (Max. size = 511)"

class RingServer: public Server {  
	public:  
	const Request *oRequest;    
	const Response *oResponse;    
};       
