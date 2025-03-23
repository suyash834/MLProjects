import sys
from src.logger import logging
import logging

def error_message_detail(error,error_detail:sys):
    _,_,exc_tb=error_detail.exc_info()
    file_name=exc_tb.tb_frame.f_code.co_filename ##exc_tb.tb_frame: gets the stack frame where the error occurred.  and f_code.co_filename: extracts the filename of the script where the error happened.
    error_message="Error occured in python script name [{0}] line number [{1}] error message[{2}]".format(
     file_name,exc_tb.tb_lineno,str(error))

    return error_message

    

class CustomException(Exception):## It builds on python built in exception class
    def __init__(self,error_message,error_detail:sys):
        super().__init__(error_message) ##This passes the error_message to the parent Exception class, so Python still recognizes it as a proper exception with a message.
        self.error_message=error_message_detail(error_message,error_detail=error_detail)
    
    def __str__(self):
        return self.error_message
    
if __name__=="__main__":
    
    try:
        a=1/0
    except Exception as e :
        logging.info("Dvide by zero error")
        raise CustomException(e,sys)
    
        
        
    