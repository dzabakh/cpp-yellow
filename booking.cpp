#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <deque>
#include <set>

using namespace std;

struct Booking{
  int64_t time;
  string hotel_name;
  int client_id;
  int room_count;
};

class Booker{
const int64_t SECONDS_PER_DAY = 86400;
public:
  Booker(): currentTime(0){};

  void Book(const Booking& i_booking){
    UpdateBookings(i_booking);
  }

  int Clients(const std::string& i_hotel_name) const{
    if (clients.count(i_hotel_name) == 0)
      return 0;
   return clients.at(i_hotel_name).size();
  }

  int Rooms(const std::string& i_hotel_name) const{
    if (rooms.count(i_hotel_name) == 0)
      return 0;
    return rooms.at(i_hotel_name);
  }

private:
  std::queue<Booking> bookings;
  std::map<string, std::map<int, int>> clients;
  std::map<string, int> rooms;
  int64_t currentTime;

  void UpdateBookings(const Booking& i_booking){
    currentTime = i_booking.time;
    while(!bookings.empty() && currentTime - bookings.front().time >= SECONDS_PER_DAY){
      ReduceRooms(bookings.front());
      RemoveClient(bookings.front());
      bookings.pop();
    }

    bookings.push(i_booking);
    AddRooms(i_booking);
    AddClients(i_booking);
  }

  void ReduceRooms(const Booking& i_booking){
    if(clients.at(i_booking.hotel_name).at(i_booking.client_id) >= i_booking.room_count){
      clients.at(i_booking.hotel_name).at(i_booking.client_id) -= i_booking.room_count;
      rooms.at(i_booking.hotel_name) -= i_booking.room_count;
     }
  }

  void RemoveClient(const Booking& i_booking){
	  if (clients.count(i_booking.hotel_name) > 0 &&
			  clients.at(i_booking.hotel_name).count(i_booking.client_id) > 0 )
		  if (clients.at(i_booking.hotel_name).at(i_booking.client_id) <= 0)
			  clients.erase(i_booking.hotel_name);
  }

  void AddRooms(const Booking& i_booking){
    if (rooms.count(i_booking.hotel_name) == 0)
      rooms[i_booking.hotel_name] = i_booking.room_count;
    else
      rooms.at(i_booking.hotel_name) += i_booking.room_count;
  }

  void AddClients(const Booking& i_booking){
    if (clients.count(i_booking.hotel_name) == 0 || clients.at(i_booking.hotel_name).count(i_booking.client_id) == 0)
      clients[i_booking.hotel_name][i_booking.client_id] = i_booking.room_count;
    else
      clients.at(i_booking.hotel_name).at(i_booking.client_id) += i_booking.room_count;
    }
};

int main(){
  Booker booker;

  int N;
  cin >> N;
  for(int n = 0; n < N; ++n){
    std::string command;
    std::cin >> command;

    if (command == "BOOK"){
      Booking booking;
      std::cin >> booking.time >> booking.hotel_name >> booking.client_id
        >> booking.room_count;
      booker.Book(booking);
    }
    else if (command == "CLIENTS"){
      std::string hotel_name;
      std::cin >> hotel_name;
      std::cout << booker.Clients(hotel_name) << std::endl;
    }
    else if (command == "ROOMS"){
      std::string hotel_name;
      std::cin >> hotel_name;
      std::cout << booker.Rooms(hotel_name) << std::endl;
    }
  }
  return 0;
}
