#include "ChainBuilder.h"

int main(int argc, char* argv[])
{
	Director director;
	director.AddChain( new Base64EncodeWork() );
	director.AddChain( new MD5EncodeWork () );
	director.AddChain( new CharcodeConvertWork () );
	director.Action();  

	return 0;
}
