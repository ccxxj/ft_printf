# ft_printf
• The prototype of ft_printf should be int ft_printf(const char *, ...);
• Recode the libc’s printf function
• It must not do the buffer management like the real printf
• It will manage the following conversions: cspdiuxX%
• It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
