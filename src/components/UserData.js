import React, { useEffect, useState } from 'react';
import axios from 'axios';

const UserData = () => {
  const [userData, setUserData] = useState(null);
  const [error, setError] = useState('');

  useEffect(() => {
    const fetchUserData = async () => {
      try {
        const token = localStorage.getItem('access_token');
        const response = await axios.get('http://localhost:8000/api/user/me', {
          headers: { Authorization: `Bearer ${token}` },
        });
        setUserData(response.data);
      } catch (err) {
        setError(err.response ? err.response.data.detail : 'Erro ao tentar acessar os dados do usuário.');
      }
    };

    fetchUserData();
  }, []);

  if (error) {
    return <p style={{ color: 'red' }}>{error}</p>;
  }

  if (!userData) {
    return <p>Carregando dados...</p>;
  }

  return (
    <div>
      <h2>Dados do Usuário</h2>
      <p>Nome: {userData.name}</p>
      <p>Email: {userData.email}</p>
      <p>Usuário: {userData.username}</p>
      <p>Status: {userData.is_active ? 'Ativado' : 'Desativado'}</p>
    </div>
  );
};

export default UserData;
