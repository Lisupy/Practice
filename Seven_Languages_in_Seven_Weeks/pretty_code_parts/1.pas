begin
	for p:=1 to 4 do
		begin
		case p of
		1: s:=max[k,t]*max[(k+t+1-1) mod n+1,l-t-1];
		2: s:=max[k,t]*min[(k+t+1-1) mod n+1,l-t-1];
		3: s:=min[k,t]*max[(k+t+1-1) mod n+1,l-t-1];
		4: s:=min[k,t]*min[(k+t+1-1) mod n+1,l-t-1]; {�����ĸ��˻�}
		end;
		if s>max[k,l] then max[k,l]:=s;
		if s<min[k,l] then min[k,l]:=s; {���������Сֵ}
	end;
end;