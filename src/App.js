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
        <UserData />
      )}
    </div>
  );
}

export default App;
