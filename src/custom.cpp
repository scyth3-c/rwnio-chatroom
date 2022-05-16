#include "custom.h"

Custom::Custom(string _name, string _hash)
{
  screen = make_shared<Screen>();
  modules = make_shared<Modules>();

  hash = make_shared<string>(_hash);
  name = make_shared<string>(_name);

  for (size_t i = 0; i < 4; i++)
  {
    messages.push_back(new MSG_t());
  }
}

Custom::~Custom()
{
  screen.reset();
  modules.reset();
  messages.~vector();
  hash.reset();
  name.reset();
}

_MSG_UP
CLOCK_UP

void Custom::charge()
{
  message_view = make_shared<Message>(*name, *hash);
  message_view->setUrl(RWNIO_HTTP_URL);
  messages[0] = new MSG_t(message_view->last(0));
  messages[1] = new MSG_t(message_view->last(1));
  messages[2] = new MSG_t(message_view->last(2));
  message_view.reset();
}

void Custom::send(string msg)
{
  message_send = make_shared<Message>(*name, *hash);
  message_send->setUrl(RWNIO_HTTP_URL);
  message_send->send(msg);
  message_send.reset();
}

void Custom::model(string _hora, string _autor, string _contenido)
{
  rwnio::screen(C,"[*] ", _hora, " [", _autor, "] : ", _contenido, N, N);
}

void Custom::viewLoop(Custom *obj)
{
  while (true)
  {

    _MSG_t = "";
    if(obj->messages[0]->contenido == "al parecer la sala no existe aun") obj->~Custom();
    obj->charge();
    obj->modules->_sys(RWNIO_SYS_CLEAR);
    obj->model(obj->messages[2]->hora, obj->messages[2]->creador, obj->messages[2]->contenido);
    obj->model(obj->messages[1]->hora, obj->messages[1]->creador, obj->messages[1]->contenido);
    obj->model(obj->messages[0]->hora, obj->messages[0]->creador, obj->messages[0]->contenido);
    std::this_thread::sleep_for(std::chrono::seconds(CLOCK));
  }
}

void Custom::sendLoop()
{
  while (true)
  {
    _MSG
        send(_MSG_t);
  }
}

void Custom::loopCustom()
{

  modules->_sys(RWNIO_SYS_CLEAR);
  thread _viewLoopThread(viewLoop, this);

  sendLoop();
  _viewLoopThread.join();
}