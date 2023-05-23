

Natural Language Dates

See Also

You can specify dates in a date type field using plain English words. This is a 
convenient alternative to specifying exact dates, as it allows you to enter commonly 
used phrases, like "a week from today", "two months ago", and "a week from next 
Sunday". The sections below list the valid formats by keyword.

When you enter a date in one of these formats, Commence figures out the exact date 
for you. For example, if today's date is 1/3/94, and you enter "one week from today" 
in a date field, Commence inserts "1/10/94" into the date field for you when you 
switch to another field or save the item.

Always check Commence's interpretation of any natural language dates you use before you save the item. Do this by moving the cursor to another field after you type in the natural language date. If the format you used is valid, the natural language will change to a real date.

Commence will, given a vague phrase, make a best guess as to your meaning. That is, a phrase like "a day after next week" would evaluate the same as "a week from today"; "next january" would evaluate to January 1st of the following year. Remember that the phrases you use should indicate an exact date.

Some phrases, like "january after next week", are too ambiguous and will generate an invalid date error if you try to save the item with such a date.

Capitalizations, punctuation, and the words "a", "the", and "day" (as in "22nd day 
of august") are optional in natural language dates, but are allowed. For example, 
"The twenty-second Day of August, 1998" could be entered as "twenty-second of august 1998" with the same result.

Note: Another method of entering dates is to double-click on any date field in an item detail or dialog box. This displays the Select Date dialog box where you can display monthly calendars to select a date and then select the OK button to return to the previous window.

Day Names

You can specify any of the following day names in a date field:

Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday

Mon, Tues, Wed, Thu, Fri, Sat, Sun

Day names specified by themselves in a date field return either the current day or the 
next day with the name specified. That is, if today is Monday and you type "Monday" 
in a date field, Commence assumes you mean today; if you type "Tuesday", Commence 
assumes you mean tomorrow, etc.

 

The date returned by a day name used in conjunction with other date formats depends on the format used. In other formats, a day can be preceded by an ordinal, as in First Tuesday, Second Thursday, etc.

Special Days

Commence recognizes the following special days and substitutes the indicated date:

Lincoln's Birthday February 12 

Veterans Day  November 11 

Veterans' Day

Columbus Day October 12 

Month Names

You can specify any of the following month names in a date field:

January, February, March, April, May, June, July, August, September, October, November, December

Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec

Month names specified by themselves in a date field return the first day of the named month in the current year. That is, if this month is April and you type "April" in a date field, Commence assumes you mean April 1st of the current year; if you type "March", Commence assumes you mean March 1st of the current year, etc.

Day Aliases

The following day aliases:

Yesterday, Yest, Today, Tomorrow, Tom

return the date of the indicated day when specified alone in a date field. The date returned by a day alias used in conjunction with other date formats depends on the format used.

Month Ordinal

Days of the month can be specified in any of the following formats:

June First, June Second, June Third, June Fourth, 

June Twenty-Second, etc.

June 1st, June 2nd, June 3rd, June 4th, June 22nd, etc.

1st of June, 2nd of June, 3rd of June, 4th of June, 

22nd of June, etc.

First of June, Second of June, Twenty-third of June, etc.

June 1, June 2, June 3, June 4, June 22, etc.

1 June, 2 June, 3 June, 4 June, 22 June, etc.

The current year is assumed unless you add a year at the end (e.g., June 2, 1995).

Last/This/Next

You can use the words Last, This, or Next in the following ways to specify a date:

Last/This/Next <DayName/MonthName>

Last/This/Next week/month/quarter/year (date returned is the first day in the appropriate week, month, quarter, or year)

<any of above formats> of Last/This/Next week/month/quarter/year

Last in this format means "previous" and not "final"; i.e., "the last day of 1989" is an invalid date format.

 

Some examples:

Next Monday

Last week

Third Tuesday of next quarter

Quarter

Specify the first day of a quarter of the year using the following formats:

1q, 2q, 3q, 4q

1st quarter, 2nd quarter, etc.

First quarter, Second quarter, etc.

The current year is assumed unless you add a year at the end (e.g., 1q 1995).

End of Period

You can specify the last day of the following formats using the form:

The end of <MonthName>/<Last/This/Next>/<Quarter>

You can add a year at the end of the above format (e.g., "end of first quarter, 1989"), except when using <Last/This/Next> (e.g., "the end of last quarter, 1998" is not valid). You can also use a year by itself (e.g., "end of 1999").

Beginning/End

You can use the words beginning and end to indicate the end of a period:

The beginning/end of the week/month/quarter/year

The beginning/end of <Last/This/Next> week/month/quarter/year

month and year can also be literal months (i.e., June, July, etc.) in the first format.

Before/After

You can use the words before or after in the following ways to specify a date:

A day before/after <any of the above formats>

A week/month/quarter/year before/after <DayAlias>/<MonthOrdinal>/<Last/This/Next>

Complex Formats

The following complex formats are also allowed. The <format> string refers to any of the above formats, though some specific forms may not be allowed if they do not specify an exact date.

 

When using complex formats, be sure to check the interpreted value of the date field before selecting Save on an item detail; do this by moving the cursor to another field after you type in the natural language date. If the format you used is valid, the natural language will change to a real date.

 

The formats below cannot be combined with one another to construct even more complex formats.

 

The subsections below present examples of complex format usage. The lists are not exhaustive since the possible combinations of formats are almost limitless.

The <Ordinal> Day/Month/Week/Quarter Of/In The Week/Month/Quarter/Year

Second month of 1993

Third day of next week

Second week in June

Fourth quarter of 1998

<format> before <format>

First thursday before may first

The friday before the beginning of next month

One month before Lincoln's Birthday, 1998

<format> after <format>

Next thursday after 1/5/99

The second friday after the beginning of next quarter

<format> from <format>

Two weeks from today

One month from yesterday

Three weeks from the beginning of next quarter

<number of> days/weeks/months/quarters/years ago

Two weeks ago

A month ago

A year ago

