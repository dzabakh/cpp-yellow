class INotifier{
public:
	virtual void Notify(const string& message) = 0;
};


class SmsNotifier: public INotifier {
public:
	SmsNotifier(const string& i_phoneNumber):phoneNumber(i_phoneNumber){}
	void Notify(const string& message){
		SendSms(phoneNumber, message);
	}
private:
	const string phoneNumber;
};

class EmailNotifier: public INotifier {
public:
	EmailNotifier(const string& i_email):email(i_email){}
	void Notify(const string& message){
		SendEmail(email, message);
	}
private:
	const string email;
};