```
def key_Stats(gather=["Total Debt/Equity",'Trailing P/E','Price/Sales','Price/Book','Profit Margin', 'Parameters that we wil learn on']):
	L = []
	statspath = path + '/_KeyStats'
	stock_list = [x[0] for x in os.walk(statspath)]
 	
	sp500 = pd.DataFrame.from_csv("YAHOO-INDEX_GSPC.csv")
	ticker_list = []
 	
	for each_dir in stock_list[1:]:
 		each_file = os.listdir(each_dir)
 		
 		ticker = each_dir.split("/")[6]
 		ticker_list.append(ticker)
 		starting_stock_value = False
 		starting_sp500_value = False
 		if len(each_file)>0:
 			for file in each_file:
 				date_stamp = datetime.strptime(file,'%Y%m%d%H%M%S.html')
 				unix_time = time.mktime(date_stamp.timetuple())
 				full_file_path = each_dir + '/' + file 
 				source = open(full_file_path, 'r').read()
				value_list = []
				for each_data in gather:
					#Preprocessing for determining stock price
				
				try:
					stock_price = float(source.split('</small><big><b>')[1].split('</b></big>')[0])
				if not(starting_stock_value):
					starting_stock_value = stock_price
				if not(starting_sp500_value):
					starting_sp500_value= sp500_value

				stock_p_change = (stock_price - starting_stock_value)/ starting_stock_value *100
				sp500_p_change = (sp500_value - starting_sp500_value)/starting_sp500_value * 100

				difference = (stock_p_change - sp500_p_change)
				if difference > 0:
					status = "outperform"
				else:
					status = "underperform"
				if value_list.count("N/A")>0:
					pass
				else:
					d  = {...} #Dictionary of parameters for the stock being traversed 
					L.append(d) #Adding to the list 
				
 	
```
				
 	
 	
	


