#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef int room_count_type;
typedef string hotel_name_type;
typedef int64_t time_type;
typedef int clientId_type;

class HotelBooker{

public:
	static constexpr int DAY_SECONDS = 86400;

	struct booking_t{
		time_type time;
		hotel_name_type hotel_name;
		clientId_type client_id;
		room_count_type room_count;
	};

	HotelBooker(): relevantBookings({}),
				   currentTime(0),
				   unique_clients({}),
				   booked_rooms_count({})
	{}

	void Book(const time_type time,
			const hotel_name_type& hotel_name,
			const clientId_type client_id,
			const room_count_type room_count){
		currentTime = time;
		ClearOldBookings();
		relevantBookings.push_back({time, hotel_name, client_id, room_count});
		UpdateUniqueClients();
		UpdateBookedRoomsCount();
	}

	const int Clients(const hotel_name_type& hotel_name) const{
		if (unique_clients.count(hotel_name) == 0) return 0;
		return unique_clients.at(hotel_name).size();
	}

	const room_count_type Rooms(const hotel_name_type& hotel_name) const{
		if (booked_rooms_count.count(hotel_name) == 0) return 0;
		return booked_rooms_count.at(hotel_name);
	}
private:
	deque<booking_t> relevantBookings;
	time_type currentTime;
	map<hotel_name_type, set<clientId_type>> unique_clients;
	map<hotel_name_type, room_count_type> booked_rooms_count;

	void ClearOldBookings(){
		if (relevantBookings.empty()) return;
		while(relevantBookings.front().time <= currentTime - DAY_SECONDS)
			relevantBookings.pop_front();
	}

	void UpdateUniqueClients(){
		unique_clients.clear();
		if (relevantBookings.empty()) return;
		for (const auto& booking: relevantBookings)
			unique_clients[booking.hotel_name].insert(booking.client_id);
	}

	void UpdateBookedRoomsCount(){
		booked_rooms_count.clear();
		if (relevantBookings.empty()) return;
		for (const auto& booking: relevantBookings)
			if (booked_rooms_count.count(booking.hotel_name) == 0)
				booked_rooms_count[booking.hotel_name] = booking.room_count;
			else
				booked_rooms_count[booking.hotel_name] += booking.room_count;
	}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  HotelBooker booker;

  int Q;
  cin >> Q;
  for (int queryNum = 0; queryNum < Q; queryNum++){
	  string command;
	  cin >> command;
	  if (command == "BOOK"){
		  time_type time;
		  hotel_name_type hotel_name;
		  int client_id;
		  room_count_type room_count;

		  cin >> time >> hotel_name >> client_id >> room_count;
		  booker.Book(time, hotel_name, client_id, room_count);
	  }
	  else if (command == "CLIENTS"){
		  hotel_name_type hotel_name;
		  cin >> hotel_name;
		  cout << booker.Clients(hotel_name) << endl;
	  }
	  else if (command == "ROOMS"){
		  hotel_name_type hotel_name;
		  cin >> hotel_name;
		  cout << booker.Rooms(hotel_name) << endl;
	  }
  }

  return 0;
}
