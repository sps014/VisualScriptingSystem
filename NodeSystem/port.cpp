#include "port.h"


Port::Port()
{

}
QPoint Port::GetWorldPosition()
{
	return Position + QPoint(static_cast<int>(Parent->position().x()), static_cast<int>(Parent->position().y()));
}