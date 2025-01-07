import React, { useState } from 'react';
import LoginForm from './components/LoginForm';
import UserData from './components/UserData';

function App() {
  const [userData, setUserData] = useState(null);

  return (
    <div>
      {!userData ? (
        <LoginForm setUserData={setUserData} />
      ) : (
        <div>
          <h1>Bem-vindo, {userData?.message}!</h1>
          <UserData userData={userData} />
        </div>
      )}
    </div>
  );
}

export default App;
