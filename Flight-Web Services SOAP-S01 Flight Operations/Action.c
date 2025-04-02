Action()
{
/*

Updated: 04.2025
Script created by Salvador Camacho

This script requires the FlightsAPI.exe to be running, located under:
C:\Program Files (x86)\OpenText\UFT One\samples\Flights Application

This script was created with best practices, so it is more resilient, such as:
* Transaction naming
* No add cookies
* No third party
* One validation per transaction
* Think times at the end of each transaction to better simulate user behavior
* DepartureCity and ArrivalCity are parametrized and randomly selected and the date is also parametrized, this applies to the first
  and second transaction

The script searches for fligths for the first two transactions and the third one creates a flight order

Runtime Settings were set to log only on errors and generate snapshot on errors, think times 75% to 150%

This script has 8 transactions
Flight-Web Services SOAP-S01-01 Get Flights
Flight-Web Services SOAP-S01-02 Get Flights
Flight-Web Services SOAP-S01-03 Create Flight Order

*/
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=GetFlightsResult",
		LAST);
	
lr_start_transaction("Flight-Web Services SOAP-S01-01 Get Flights");

	web_service_call( "StepName=GetFlights_102",
		"SOAPMethod=Flights_Service|FlightsServiceMethods|GetFlights",
		"ResponseParam=response",
		"Service=Flights_Service",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1699436746.inf",
		BEGIN_ARGUMENTS,
		"DepartureCity={City}",
		"ArrivalCity={City}",
		"FlightDate={futureDate}",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);
		
lr_end_transaction("Flight-Web Services SOAP-S01-01 Get Flights", LR_AUTO);

	lr_think_time(10);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=GetFlightsResult",
		LAST);
	
lr_start_transaction("Flight-Web Services SOAP-S01-02 Get Flights");

	web_service_call( "StepName=GetFlights_102",
		"SOAPMethod=Flights_Service|FlightsServiceMethods|GetFlights",
		"ResponseParam=response",
		"Service=Flights_Service",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1699436746.inf",
		BEGIN_ARGUMENTS,
		"DepartureCity={City}",
		"ArrivalCity={City}",
		"FlightDate={futureDate}",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);
	
lr_end_transaction("Flight-Web Services SOAP-S01-02 Get Flights", LR_AUTO);
	                  
	lr_think_time(10);
	
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=CreateFlightOrder",
		LAST);

lr_start_transaction("Flight-Web Services SOAP-S01-03 Create Flight Order");

	web_service_call( "StepName=CreateFlightOrder_101",
		"SOAPMethod=Flights_Service|FlightsServiceMethods|CreateFlightOrder",
		"ResponseParam=response",
		"Service=Flights_Service",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1699442714.inf",
		BEGIN_ARGUMENTS,
		"xml:FlightOrder="
			"<FlightOrder>"
				"<Class>First</Class>"
				"<CustomerName>John Doe</CustomerName>"
				"<DepartureDate>11/09/2025</DepartureDate>"
				"<FlightNumber>11148</FlightNumber>"
				"<NumberOfTickets>1</NumberOfTickets>"
			"</FlightOrder>",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);

lr_end_transaction("Flight-Web Services SOAP-S01-03 Create Flight Order", LR_AUTO);

	lr_think_time(10);

	
	return 0;
}
