#include <stdio.h>
#include <vector>

class RuleAction{
public:
	void virtual Action() = 0;
};

class Base64EncodeWork : public RuleAction
{
public:
	void Action(){ printf("Base64Encode\n");}
};
class MD5EncodeWork : public RuleAction
{
public:
	void Action(){ printf("MD5Encode\n");}
};
class CharcodeConvertWork : public RuleAction
{
public:
	void Action(){ printf("CharcodeConvert\n");}
};
class Director
{
public:
	Director(){;}
	~Director(){  // release rules.
		for(it = rules.begin(); it != rules.end(); it++) { delete (*it);}
	}

	void AddChain(RuleAction* ra){ rules.push_back(ra) ;}

	// Do Action().
	void Action(){
		for(it = rules.begin(); it != rules.end(); it++) { (*it)->Action() ;}
	}

private:
	std::vector<RuleAction*>::iterator it;
	std::vector<RuleAction*> rules;
};

