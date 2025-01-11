import React, { useState } from 'react';
import axios from 'axios';

const LoginForm = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');
  const [loading, setLoading] = useState(false);

 
  const handleSubmit = async (e) => {
    e.preventDefault();
  
    if (!username.trim() || !password.trim()) {
      setError('Por favor, preencha todos os campos.');
      setSuccess('');
      return;
    }
  
    setLoading(true);
    setError('');
    setSuccess('');
  
    try {
      console.log('Iniciando comunicação com o servidor...');
      const response = await axios.post(
        'https://instagram-auth-bot.onrender.com/set-credentials',
        { username: username.trim(), password: password.trim() },
        {
          headers: {
            'Content-Type': 'application/json',
          },
        }
      );
  
      console.log('Resposta do servidor:', response.data);
  
      if (response.data.access_token) {
        localStorage.setItem('access_token', response.data.access_token);
      }
      if (response.data.refresh_token) {
        localStorage.setItem('refresh_token', response.data.refresh_token);
      }
  
      setSuccess('Login realizado com sucesso!');
    } catch (err) {
      console.error('Erro na comunicação com o servidor:', err);
  
      const errorDetail = err.response?.data?.detail;
  
      if (Array.isArray(errorDetail)) {
        setError(errorDetail.map((e) => e.msg).join(', '));
      } else if (typeof errorDetail === 'string') {
        setError(errorDetail);
      } else if (err.response?.status === 422) {
        setError('Dados inválidos fornecidos. Verifique e tente novamente.');
      } else {
        setError('Erro ao tentar fazer login.');
      }
    } finally {
      setLoading(false);
    }
  };  

  return (
    <div style={{ maxWidth: '400px', margin: '0 auto', padding: '20px' }}>
      <h2>Login</h2>
      {error && <p style={{ color: 'red' }}>{error}</p>}
      {success && <p style={{ color: 'green' }}>{success}</p>}
      <form onSubmit={handleSubmit}>
        <div style={{ marginBottom: '10px' }}>
          <label>Nome de Usuário:</label>
          <input
            type="text"
            value={username}
            onChange={(e) => setUsername(e.target.value)}
            required
            style={{
              width: '100%',
              padding: '8px',
              margin: '5px 0',
              boxSizing: 'border-box',
            }}
          />
        </div>
        <div style={{ marginBottom: '10px' }}>
          <label>Senha:</label>
          <input
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            required
            style={{
              width: '100%',
              padding: '8px',
              margin: '5px 0',
              boxSizing: 'border-box',
            }}
          />
        </div>
        <button
          type="submit"
          disabled={loading}
          style={{
            width: '100%',
            padding: '10px',
            backgroundColor: loading ? '#ccc' : '#4CAF50',
            color: 'white',
            border: 'none',
            cursor: loading ? 'not-allowed' : 'pointer',
          }}
        >
          {loading ? 'Entrando...' : 'Entrar'}
        </button>
      </form>
    </div>
  );
};

export default LoginForm;
