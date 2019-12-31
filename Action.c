Action()
{

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("blazedemo.com", 
		"URL=http://blazedemo.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_auto_header("Origin", 
		"http://blazedemo.com");

	lr_think_time(9);

	web_submit_data("reserve.php", 
		"Action=http://blazedemo.com/reserve.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://blazedemo.com/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=fromPort", "Value=Portland", ENDITEM, 
		"Name=toPort", "Value=Berlin", ENDITEM, 
		LAST);

	web_submit_data("purchase.php", 
		"Action=http://blazedemo.com/purchase.php", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://blazedemo.com/reserve.php", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flight", "Value=43", ENDITEM, 
		"Name=price", "Value=472.56", ENDITEM, 
		"Name=airline", "Value=Virgin America", ENDITEM, 
		"Name=fromPort", "Value=Portland", ENDITEM, 
		"Name=toPort", "Value=Berlin", ENDITEM, 
		LAST);

	// This is my change for learning.
	web_custom_request("web_custom_request",
		"URL=www.example.com",
		"Method=GET",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Body=",
		LAST);

	return 0;
}