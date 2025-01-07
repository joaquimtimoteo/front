import React from 'react';

const UserData = ({ userData }) => {
  return (
    <div>
      <h3>Detalhes do Usuário</h3>
      <p>Email: {userData?.email}</p>
      <p>Nome: {userData?.message}</p> {/* Supondo que "message" seja o nome do usuário */}
      {/* Outros dados que você queira exibir */}
      <button
        onClick={() => {
          localStorage.removeItem('access_token');
          localStorage.removeItem('refresh_token');
          window.location.reload(); // Faz o refresh da página para voltar ao login
        }}
      >
        Sair
      </button>
    </div>
  );
};

export default UserData;
