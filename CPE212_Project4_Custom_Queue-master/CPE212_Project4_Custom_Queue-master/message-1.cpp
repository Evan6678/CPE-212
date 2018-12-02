#include "message.h"

Message::Message()
{
  message = UNKNOWN;
}

void Message::SetPriority(Priorities p)
{
  priority = p;
}

void Message::SetMessage(string msg)
{
  message = msg;
}

Priorities Message::GetPriority() const
{
  return priority;
}

string Message::GetMessage() const
{
  return message;
}
