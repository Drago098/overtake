#!/usr/bin/env python
# coding: utf-8

# In[4]:


import tensorflow as tf
import pandas as pd 
ecu = pd.read_csv(r'/Users/mac/Downloads/final sheet.csv')
ecu


# In[4]:


y = ecu.STEERINGANGLE
print(y)


# In[5]:


z = ecu['STEERINGANGLE'].describe()
z


# In[7]:


z = ecu['STEERINGANGLE'].describe()
z


# In[6]:


ecu.head()


# In[8]:


from sklearn.tree import DecisionTreeRegressor
ecu_model = DecisionTreeRegressor()
ecu_model.fit(x,y)


# In[9]:


from sklearn.model_selection import train_test_split
train_X, val_X, train_y, val_y = train_test_split(x, y, random_state=1)


# In[10]:


ecu_model = DecisionTreeRegressor(random_state = 1)
ecu_model.fit(train_X,train_y)
ecu_predictions = ecu_model.predict(val_X)


# In[11]:


import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')
import seaborn as sns


# In[13]:


plt.figure(figsize=(14,6))

sns.barplot(x = ecu['DISTANCE'], y = ecu.STEERINGANGLE)
plt.figure(figsize = (12,6))
sns.barplot(x = ecu['DISTANCELAT'],y = ecu.STEERINGANGLE)


# In[15]:


plt.figure(figsize=(14,6))

sns.lineplot(x = ecu['DISTANCE'], y = ecu.STEERINGANGLE)
plt.figure(figsize = (12,6))
sns.lineplot(x = ecu['DISTANCELAT'], y = ecu.STEERINGANGLE)
sns.scatterplot(x = ecu['DISTANCELAT'],y = ecu.STEERINGANGLE)


# In[51]:


plt.figure(figsize=(14,6))

sns.barplot(x = ecu['RPM'], y = ecu.STEERINGANGLE)


# In[ ]:




