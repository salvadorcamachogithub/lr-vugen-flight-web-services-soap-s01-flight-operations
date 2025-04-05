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
* DepartureCity and ArrivalCity are parametrized and randomly selected and the date is also parametrized, this applies to the first and second transaction

The script searches for fligths for the first two transactions and the third one creates a flight order

Runtime Settings were set to log only on errors and generate snapshot on errors, think times 75% to 150%

This script has 3 transactions:  
Flight-Web Services SOAP-S01-01 Get Flights  
Flight-Web Services SOAP-S01-02 Get Flights  
Flight-Web Services SOAP-S01-03 Create Flight Order