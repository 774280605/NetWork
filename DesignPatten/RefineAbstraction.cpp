#include "pch.h"
#include "RefineAbstraction.h"
#include <iostream>


RefineAbstraction::RefineAbstraction(Implementor* implementor):
implementor_(implementor)
{

}

void RefineAbstraction::show() {
	implementor_->show();	
}
