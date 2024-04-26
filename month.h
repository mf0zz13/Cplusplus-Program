#ifndef MONTH_H
#define MONTH_H

class month {

	public:
		month(); // default construtor
		void setOpeningAmount(double t_openingAmount); // set opening amount
		void setOpeningAmountWithDeposit(double t_openingAmountWithDeposit); // set opening amout with deposit
		void setMonthlyDeposit(double t_depositAmount); // set monthly deposit
		void setAnnualIntrestRate(double t_annualIntrestRate); // sett anual intrest rate
		void setSumOpeningAndDeposit(double t_sumOpeningAndDeposit); // set sum opening amount and deposit amount
		void setIntrestAcrued(double t_intrestAcrued); // set intrest acrued
		void setIntrestAcruedWithDeposit(double t_intrestAcruedWithDeposit); // set intrest acrued with deposit
		void setClosingBalance(double t_closingBalance); // set closing balance
		void setClosingBalanceWithDeposit(double t_closingBalanceWithDeposit); // set closing balance
		void setMonthNumber(int t_monthNumber); // set number of months
		void setNumberOfYears(int t_numberOfYears); // set number of years
		double getOpeningAmount(); // get opening amount
		double getOpeningAmountWithDeposit(); // get opening amout with depoist
		double getMonthlyDeposit(); // get monthly deposit
		double getAnnualIntrestRate(); // get annual intrest rate
		double getSumOpeningAndDeposit(); // get sum of the opening and deposit amount
		double getIntrestAcrued(); // get intrest acrued
		double getIntrestAcruedWithDeposit(); // get intrest acrued with deposit
		double getClosingBalance(); // get closing balance
		double getClosingBalanceWithDeposit(); // get closing balance with deposit
		double getMonthNumber(); // get number of months
		double getNumberOfYears(); // get number of years

	private:
		double m_openingAmount; // var to store opening amount
		double m_openingAmountWithDeposit; // var to store the opening amount with the deposit
		double m_monthlyDeposit; // var to store the monthly deposit
		double m_annualIntrestRate; // var to store the annual intrest rate
		double m_sumOpeningAndDeposit; // var to store the sum of the opening and deposit amount
		double m_intrestAcrued; // var to store the intrest acrued
		double m_intrestAcruedWithDeposit; // var to store the intrest acrued with the deposit
		double m_closingBalance; // var to store the closing balance
		double m_closingBalanceWithDeposit; // var to store the closing balance with deposit
		int m_monthNumber; // var to store the number of months
		int m_numberOfYears; // var to store the number of years
		
};

#endif // !MONTH_H

