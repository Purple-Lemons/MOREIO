#include "InputNode.h"

InputNode::InputNode()
{
}


InputNode::~InputNode()
{
}

float GenericNode::input(float _value)
{
	if (_value >= 0.5f)
	{
		state = true;
	}
	else
	{
		state = false;
	}

	//Simply passes the value to the next layer
	return _value;
}

void InputNode::output()
{

}
