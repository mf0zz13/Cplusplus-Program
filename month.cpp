#include "month.h"
using namespace std;

month::month() { // defualt constructor for month
	m_openingAmount = 0.0;
	m_openingAmountWithDeposit = 0.0;
	m_monthlyDeposit = 0.0;
	m_annualIntrestRate = 0.0;
	m_sumOpeningAndDeposit = 0.0;
	m_intrestAcrued = 0.0;
	m_intrestAcruedWithDeposit = 0.0;
	m_closingBalance = 0.0;
	m_closingBalanceWithDeposit = 0.0;
	m_monthNumber = 0;
}

void month::setOpeningAmount(double t_openingAmount) { // set opening amount
	m_openingAmount = t_openingAmount;
}

void month::setOpeningAmountWithDeposit(double t_openingAmountWithDeposit) { // set opening amout with deposit
	m_openingAmountWithDeposit = t_openingAmountWithDeposit;
}

void month::setMonthlyDeposit(double t_depositAmount) { // set monthly deposit amount
	m_monthlyDeposit = t_depositAmount;
}

void month::setAnnualIntrestRate(double t_annualIntrestRate) { // set annual intrest rate
	m_annualIntrestRate = t_annualIntrestRate;
}

void month::setSumOpeningAndDeposit(double t_sumOpeningAndDeposit) { // set sum of opening and deposit amount
	m_sumOpeningAndDeposit = t_sumOpeningAndDeposit;
}

void month::setIntrestAcrued(double t_intrestAcrued) { // set intrest acrued
	m_intrestAcrued = t_intrestAcrued;
}

void month::setIntrestAcruedWithDeposit(double t_intrestAcruedWithDeposit) { // set intrest acrued with deposit
	m_intrestAcruedWithDeposit = t_intrestAcruedWithDeposit;
}

void month::setClosingBalance(double t_closingBalance) { // set closing balance
	m_closingBalance = t_closingBalance;
}

void month::setClosingBalanceWithDeposit(double t_closingBalanceWithDeposit) { // set closing balance with deposit
	m_closingBalanceWithDeposit = t_closingBalanceWithDeposit;
}

void month::setMonthNumber(int t_monthNumber) { // set number of months
	m_monthNumber = t_monthNumber;
}

void month::setNumberOfYears(int t_numberOfYears) { // set number of years
	m_numberOfYears = t_numberOfYears;
}

double month::getOpeningAmount() { // get opening amount
	return m_openingAmount;
}

double month::getOpeningAmountWithDeposit() { // get opening amount with deposits
	return m_openingAmountWithDeposit;
}

double month::getMonthlyDeposit() { // get monthly deposit
	return m_monthlyDeposit;
}

double month::getAnnualIntrestRate() { // get annual intrest rate
	return m_annualIntrestRate;
}

double month::getSumOpeningAndDeposit() { // get sum of the opening and deposit amount
	return m_sumOpeningAndDeposit;
}

double month::getIntrestAcrued() { // get intrest acrued
	return m_intrestAcrued;
}

double month::getIntrestAcruedWithDeposit() { // get intrest acrued with deposit
	return m_intrestAcruedWithDeposit;
}

double month::getClosingBalance() { // get closing balance
	return m_closingBalance;
}

double month::getClosingBalanceWithDeposit() { // get closing balance with deposit
	return m_closingBalanceWithDeposit;
}

double month::getMonthNumber() { // get number of months
	return m_monthNumber;
}

double month::getNumberOfYears() { // get number of years
	return m_numberOfYears;
}