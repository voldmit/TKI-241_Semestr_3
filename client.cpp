#include "client.h"


Client::Client(const std::string& name) : name_(name) {}
std::string Client::GetName() const 
{ 
	return name_;
}