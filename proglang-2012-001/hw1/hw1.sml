(*  solutions should work for any int*int*int except where noted. *)

fun is_order(date1: (int * int * int), date2 : (int * int * int)) =
    if #1 date1 = #1 date2
    then if #2 date1 = #2 date2
	 then #3 date1 < #3 date2
	 else #2 date1 < #2 date2
    else #1 date1 < #1 date2 
		     

fun number_in_month(dates : (int * int * int) list, month : int) = 
    if null dates
    then 0
    else if (#2 (hd dates)) = month
    then 1 + number_in_month(tl dates, month)
    else 0 + number_in_month(tl dates, month)
			    
			   
					   
fun number_in_months(dates : (int * int * int) list, months : int list) =
    if null months
    then 0
    else number_in_month(dates, hd months) + number_in_months(dates, tl months)

							     
fun dates_in_month(dates : (int * int * int) list, month : int) =
    if null dates
    then []
    else if #2 (hd dates) = month
    then hd dates :: dates_in_month(tl dates, month)
    else dates_in_month(tl dates, month)

fun dates_in_months(dates : (int * int * int) list, months : int list) =
    if null dates
    then []
    else dates_in_month(dates, hd months) @ dates_in_months(dates, tl months)

							   (* . Do not worry about the case where the list has too few elements: your function may apply hd or tl to the empty list in this case, which is okay. *)

fun get_nth(elems : string list, n : int) =
    if n = 1
    then hd elems
    else get_nth(tl elems, n - 1)


		
fun date_to_string(date : int * int * int) =
    let
	val months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    in
	get_nth(months, #2 date) ^ " " ^ Int.toString(#3 date) ^ ", " ^ Int.toString(#1 date)
    end

(* Assume the entire list sums to more than the passed in value; it is okay for an exception to occur if this is not the case. *)
fun number_before_reaching_sum(sum : int, nums : int list) = 
    if sum <= hd nums
    then 0
    else 1 + number_before_reaching_sum(sum - (hd nums), tl nums)
				       

fun what_month(day : int) = 
    number_before_reaching_sum(day, [0, 31,28,31,30,31,30,31,31,30,31,30,31])

			     
			     
fun month_range(day1 : int, day2 : int) =
    if day1 > day2
    then []
    else what_month(day1) :: month_range(day1+1, day2)
				       
fun oldest(dates : (int * int * int) list) =
    if null dates
    then NONE
    else if null (tl dates)
    then SOME(hd dates)
    else
	let
	    val tl_ans = oldest(tl dates)
	in
	    if isSome tl_ans andalso is_order(hd dates, valOf tl_ans)
	    then SOME (hd dates)
	    else tl_ans
	end

fun number_in_months_challenge(dates : (int * int * int) list, months : int list) =
    0
fun dates_in_months_challenge(dates : (int * int * int ) list, months : int list) =
    []
fun reasonable_date(date : (int * int * int)) =
    false
	
	    
