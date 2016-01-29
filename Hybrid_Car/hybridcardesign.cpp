/*
Part 1:
Prompt user to enter their estimated miles driven per year.
	Store as int miles_year
Prompt user to enter the estimated cost of gas per gallon.
	Store as double cost_gallon_gas
Prompt user to enter cost of hybrid car.
	Store as double hybrid_cost
Prompt user to enter hybrid mpg.
	Store as int hybrid_mpg
Prompt user to enter estimated resale of hybrid after 5 years.
	Store as double hybrid_resale

Prompt user to enter cost of traditional car.
	Store as double trad_cost
Prompt user to enter mpg of traditional car.
	Store as int trad_mpg
Prompt user to enter estmated resale of traditional after 5 years.
	Store as double trad_resale.

Prompt user to enter buying criteria (either "Gas" consumption or "Total" cost)
Include if else statement that requires all inputs to be positive values.

Part: 2
For Hybrid:
	Calculate gallons of gas consumed per year.
		miles_year / hybrid_mpg
			Store as double hybrid_gas_consumption_year
	Calculate total cost of gas
		hybrid_gas_consumption_year * cost_gallon_gas
			Store as double hybrid_gas_cost_year
	IF user entered "gas" print gas consumption (hybrid_gas_consumption_year) first
	ELSE print hybrid_gas_cost_year

For Traditional:
	Calculate the gallons of gas consumed per year.
		miles_year / trad_mpg
			Store as double trad_gas_consumption_year
	Calculate total cost of gas
		trad_gas_consumption_year * cost_gallon_gas
			Store as double trad_gas_cost_year.
	IF user entered "gas", print trad_gas_consumption_year first
	ELSE print trad_gas_cost_year
*/

#include <iostream>