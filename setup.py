from setuptools import find_packages,setup
from typing import List
HYPHEN_E_DOT='-e .' ## It is used to tell that the setup file exits through the requirements.txt and build the package along with downloading the file.
def get_requirements(file_path:str)->List[str]:
    '''
    This function will return the list of requiremnents
    '''
    requirements=[]
    with open(file_path) as file_obj:## File if openens with the given file path
        requirements=file_obj.readlines() ## th elines are read line by line
        requirements=[req.replace("\n","") for req in requirements] ## the "\n" also gets read while changnig the line which is to be ommited
        if HYPHEN_E_DOT in requirements:## since "-e ." also exists in the requiremts.txt we need to remove from the string list
            requirements.remove(HYPHEN_E_DOT)
    return requirements
setup(
name='MLProjects',
version='0.0.1',
author='Suyash',
author_email='Suyash.dixit834@gmail.com',
packages=find_packages(),##It is used to find the files with __init__.py
install_requires=get_requirements('requirements.txt')##['pandas','numpy','seaborn'] if less packages required
## we use  the function method of defining the packages required to install when there number are large
)