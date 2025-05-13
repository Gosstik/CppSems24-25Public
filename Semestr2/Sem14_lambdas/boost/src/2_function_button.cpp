#include <boost/bind.hpp>
#include <boost/function.hpp>

struct Button {
  boost::function<void()> on_click;
};

struct Player {
  void Play();
  void Stop();
};

Button play_button, stop_button;
Player player;

void Connect() {
  play_button.on_click = boost::bind(&Player::Play, &player);
  stop_button.on_click = boost::bind(&Player::Stop, &player);
}

int main() {
  // ...
}
